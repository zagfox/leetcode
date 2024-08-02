---
date:   2024-08-01
---

# Leetcode 53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

## Brute force
Iterate all possible [start, end] combinations, compute sum for each combination.
Time Complexity: O(N^2)

## Dynamic Programing
Define dp(i) as the max sum, if using the i'th number as the start. Suppose we know dp(i+1), when it comes to dp(i), there are two possibilities. One is that dp(i+1) is a positive number, then dp(i), combines itself with the sequence after it. Two is that dp(i-1) is negative number, then dp(i) just include itself.

## Java Code
<pre>
<code>
class Solution {
    public int maxSubArray(int[] nums) {
        int N = nums.length;
        int[] dp = new int[N];
        dp[N-1] = nums[N-1];
        for (int i = N-2; i >= 0; --i) {
            if (dp[i+1] > 0) {
                dp[i] = nums[i] + dp[i+1];
            } else {
                dp[i] = nums[i];
            }
        }
        int max = dp[0];
        for (int i = 0; i < N; ++i) {
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
</code>
</pre>