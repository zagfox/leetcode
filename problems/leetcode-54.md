---
date:   2024-07-22
---

# Leetcode 54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

## Recursion
Transform the overall problem, into multiple smaller problems of outputing one straight line of sequence for a sub matrix.

## Java Code
<pre>
<code>
class Solution {
    // Output one line sequence for a sub matrix. [start, end] inclusive.
    // Direction, 0(right), 1(down), 2(left), 3(up)
    public List<Integer> oneLine(int[][] matrix, int xStart, int xEnd, int yStart, int yEnd, int direction) {
        List<Integer> output = new LinkedList<>();
        if (direction == 0) {
            for (int j = yStart; j <= yEnd; ++j) {
                output.add(matrix[xStart][j]);
            }
        }
        if (direction == 1) {
            for (int i = xStart; i <= xEnd; ++i) {
                output.add(matrix[i][yEnd]);
            }
        }
        if (direction == 2) {
            for (int j = yEnd; j >= yStart; --j) {
                output.add(matrix[xEnd][j]);
            }
        }
        if (direction == 3) {
            for (int i = xEnd; i >= xStart; --i) {
                output.add(matrix[i][yStart]);
            }
        }
        return output;
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        int xStart = 0, xEnd = matrix.length - 1;
        int yStart = 0, yEnd = matrix[0].length - 1;
        int direction = 0;
        List<Integer> output = new LinkedList<>();
        while (xStart <= xEnd && yStart <= yEnd) {
            output.addAll(oneLine(matrix, xStart, xEnd, yStart, yEnd, direction));
            if (direction == 0) {
                ++xStart;
                direction = 1;
            } else if (direction == 1) {
                --yEnd;
                direction = 2;
            } else if (direction == 2) {
                --xEnd;
                direction = 3;
            } else if (direction == 3) {
                ++yStart;
                direction = 0;
            }
        }
        return output;
    }
}
</code>
</pre>
