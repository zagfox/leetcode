---
date:   2024-06-18
---

# Leetcode 322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
 
## Dynamic Programing
Having an array of length N+1, starting from smaller number. One amount, can be made up by using 1 of coin + (the way to make up N-coin). Choose the minimum as the required coin number.

## Java Code
<pre>
<code>
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = -1;
        }
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                int base = i - coin;
                if (base >= 0 && dp[base] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[base] + 1;
                    } else {
                        dp[i] = Math.min(dp[i], dp[base]+1);
                    }
                }
            }
        }
        return dp[amount];
    }
}
</code>
</pre>