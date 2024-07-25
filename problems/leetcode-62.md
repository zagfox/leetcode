---
date:   2024-07-25
---

# Leetcode 62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

## Backtracking
Move the robot from the initial position, recursively try all paths. When it hits the destination, record one path.

It contains duplicates. At a certain point, multiple incoming path may came. And it computes this node to destination's unique paths again.

## Dynamic programming
Use dp[i][j] to denote the unique path from (0,0) to i, j. Because the robot can only move to right, and move down. 
dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
When updating this dp, use two nested for loop, one from top to down, the other left to right. (Prove of this may be tricky)

## Math
There is a total of (m+n-2) steps to take. (m-1) steps are moving down, (n-1) steps are moving right. The problem is to select (m-1) cards from (m+n-2) positions. Then C(m+n-2, m-1).

## Java Code
<pre>
<code>
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
}
</code>
</pre>
