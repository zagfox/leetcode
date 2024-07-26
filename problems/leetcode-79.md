---
date:   2024-07-26
---

# Leetcode 79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

## DFS
Starting from one position, search its neighbors to check if that is the next letter. Do this recursively.

Pay attention to the visiting check, it needs to be set back to false before funciton return.

## Java Code
<pre>
<code>
class Solution {
    private int M, N;
    public boolean search(int x, int y, char[][] board, String word, int pos, boolean[][] visiting) {
        if (pos == word.length()) {
            return true;
        }

        if (visiting[x][y]) {
            return false;
        }
        if (word.charAt(pos) != board[x][y]) {
            return false;
        }
        if (pos == word.length()-1) {
            return true;
        }
        visiting[x][y] = true;
        int[][] directions = {{1, 0},{-1,0},{0,1},{0,-1}};
        for (int[] direction : directions) {
            int newX = x + direction[0];
            int newY = y + direction[1];
            if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
                continue;
            }
            if (visiting[newX][newY]) {
                continue;
            }
            if (search(newX, newY, board, word, pos+1, visiting)) {
                visiting[x][y] = false;
                return true;
            }
        }
        visiting[x][y] = false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        M = board.length;
        N = board[0].length;
        boolean[][] visiting = new boolean[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (search(i, j, board, word, 0, visiting)) {
                    return true;
                }
            }
        }
        return false;
    }
}
</code>
</pre>
