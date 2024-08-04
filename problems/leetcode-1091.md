---
date:   2024-08-04
---

# Leetcode 1091. Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

## Dynamic programming
In this question, it can move to all directions. So using DP will have issue. As dp update is always in a sequence, and that sequence may not reach the answer.

## BFS
Starting from source, mark the nodes that it can reach in one turn, until it hit the destination.

There is a visited data structure to help record which point are already pushed to the queue.

## Java Code
<pre>
<code>
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int N = grid.length;
        if (grid[0][0] == 1 || grid[N-1][N-1] == 1) {
            return -1;
        }
        // Mark to true after push the point to queue.
        boolean[][] visited = new boolean[N][N];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0*N + 0);
        visited[0][0] = true;
        int step = 1;
        while (!queue.isEmpty()) {
            Queue<Integer> newQueue = new LinkedList<>();
            //System.out.println("step is " + step);
            while (!queue.isEmpty()) {
                int encoded = queue.poll();
                int x = encoded / N;
                int y = encoded % N;
                //System.out.println("visiting " + x + " " + y);
                if (x == N-1 && y == N-1) {
                    return step;
                }
                int[][] directions = new int[][] {
                    {-1, -1}, {-1, 0}, {-1, 1},
                    {0, -1}, {0, 1},
                    {1, -1}, {1, 0}, {1, 1},
                };
                for (int[] direction : directions) {
                    int newX = x + direction[0];
                    int newY = y + direction[1];
                    if (newX < 0 || newX >= N || newY < 0 || newY >= N) {
                        continue;
                    }
                    if (visited[newX][newY]) {
                        continue;
                    }
                    if (grid[newX][newY] == 1) {
                        continue;
                    }
                    newQueue.add(newX*N + newY);
                    visited[newX][newY] = true;
                }
            }
            queue = newQueue;
            ++step;
        }
        return -1;
    }
}
</code>
</pre>
