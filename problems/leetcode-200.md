---
date:   2024-07-16
---

# Leetcode 200. Number of Islands

Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

## DFS
Traverse all points in the grid. For each point, do DFS, traverse all its connecting land neighbors. After traverse, mark self as 0.

## DFS Java Code
<pre>
<code>
class Solution {
    public void dfs(int x, int y, char[][] grid, boolean[][] visited) {
        if (grid[x][y] == '0') {
            return;
        }
        if (visited[x][y]) {
            return;
        }
        // Avoid revisiting during dfs.
        visited[x][y] = true;
    
        int M = grid.length;
        int N = grid[0].length;
        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int[] direction : directions) {
            int newX = x + direction[0];
            int newY = y + direction[1];
            if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
                continue;
            }
            if (visited[newX][newY]) {
                continue;
            }
            if (grid[newX][newY] == '0') {
                continue;
            }
            dfs(newX, newY, grid, visited);
        }
        grid[x][y] = '0';
    }
    public int numIslands(char[][] grid) {
        int cnt = 0;
        int M = grid.length;
        int N = grid[0].length;
        boolean[][] visited = new boolean[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                }
                dfs(i,j,grid,visited);
            }
        }
        return cnt;
    }
}
</code>
</pre>
