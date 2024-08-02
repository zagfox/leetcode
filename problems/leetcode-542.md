---
date:   2024-06-28
---

# Leetcode 542. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

## Breath First Search
For a cell that is 0, distance to 0. Then all its non-0 neighbors distance is 1. First round of BFS find all cells with 0, the expanding to its neighbors. After several rounds, all numbers in the matrix are visited.

The 'boolean[][] visited' map need some caution. It should be marked as visited after inserting to queue (rather than being poped out from queue). In this way, it can avoid double inserting to the queue.

## Java Code
<pre>
<code>
class Solution {
    int M, N;
    public int toToken(int x, int y) {
        return x * N + y;
    }
    public int toToken(int[] pos) {
        return pos[0] * N + pos[1];
    }
    public int[] fromToken(int token) {
        return new int[]{token / N, token % N};
    }
    public int[][] updateMatrix(int[][] mat) {
        M = mat.length;
        N = mat[0].length;
        // Mark as true as long as it is in queue. To prevent double insertion to queue.
        boolean[][] visited = new boolean[M][N];
        int[][] output = new int[M][N];
        // Integer z =  x*N + y; Then later x = z/N, y = z%N;
        LinkedList<Integer> queue = new LinkedList<>();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (mat[i][j] == 0) {
                    queue.add(toToken(i, j));
                    visited[i][j] = true;
                }
            }
        }
        int round = 0;
        while (!queue.isEmpty()) {
            LinkedList<Integer> newQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                int[] pos = fromToken(queue.pop());
                int x = pos[0], y = pos[1];
                
                if (mat[x][y] != 0) {
                    output[x][y] = round;
                }
                int[][] directions = new int[][] {
                    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
                };
                for (int[] direction : directions) {
                    int newX = x + direction[0];
                    int newY = y + direction[1];
                    if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
                        continue;
                    }
                    if (visited[newX][newY]) {
                        continue;
                    }
                    newQueue.add(toToken(newX, newY));
                    visited[newX][newY] = true;
                }
            }
            queue = newQueue;
            ++round;
        }
        return output;
    }
}
</code>
</pre>

## 2 Rounds Sweep
The idea is to expand 0's impact to all the cells. But not using BFS. Just expanding from all the
zeros, to all directions. One pass is to right + down, the second pass is to left + up. This method may need more strict to prove that it works. But this is already a popular leetcode answer.


## Java Code
<pre>
<code>
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int M = mat.length, N = mat[0].length;
        int[][] output = new int[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                output[i][j] = M + N + 1;
            }
        }
        // First pass, to right + down
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (mat[i][j] == 0) {
                    output[i][j] = 0;
                    continue;
                }
                if (i > 0) {
                    output[i][j] = Math.min(output[i][j], output[i-1][j] + 1);
                }
                if (j > 0) {
                    output[i][j] = Math.min(output[i][j], output[i][j-1] + 1);
                }
            }
        }
        // Second pass, to left + up
        for (int i = M-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    output[i][j] = 0;
                    continue;
                }
                if (i < M-1) {
                    output[i][j] = Math.min(output[i][j], output[i+1][j] + 1);
                }
                if (j < N-1) {
                    output[i][j] = Math.min(output[i][j], output[i][j+1] + 1);
                }
            }
        }
        return output;
    }
}
</code>
</pre>