---
date:   2024-07-16
---

# Leetcode 994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

## Simulation
Simulate the way that orange rot. Each iteration, select grid to became rot.

## Java Code
<pre>
<code>
class Solution {
    private int M, N;
    // Return the number of newly rotten oranges.
    public int oneIteration(int[][] grid) {
        // Each round, mark newly rotten oranges to 3.
        // Then later mark them to 2.
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int state = grid[i][j];
                if (state == 0 || state == 1 || state == 3) {
                    continue;
                }
                int[][] directions = new int[][]{
                    {1,0},{-1,0},{0,1},{0,-1}
                };
                for (int[] direction : directions) {
                    int x = i + direction[0];
                    int y = j + direction[1];
                    if (x < 0 || x >= M || y < 0 || y >= N) {
                        continue;
                    }
                    if (grid[x][y] == 1) {
                        grid[x][y] = 3;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 3) {
                    ++cnt;
                    grid[i][j] = 2;
                }
            }
        }
        return cnt;
    }
    // If the grid contains fresh oranges
    public boolean hasFresh(int[][] grid) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    return true;
                }
            }
        }
        return false;
    }
    public int orangesRotting(int[][] grid) {
        M = grid.length;
        N = grid[0].length;
        if (!hasFresh(grid)) {
            return 0;
        }
        
        int iteration = 0;
        while (true) {
            ++iteration;
            int newlyRot = oneIteration(grid);
            if (!hasFresh(grid)) {
                break;
            }
            if (newlyRot == 0) {
                return -1;
            }
        }
        return iteration;
    }
}
</code>
</pre>
