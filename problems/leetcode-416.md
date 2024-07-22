---
date:   2024-07-22
---

# Leetcode 416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

## 2 dimension Dynamic programing

The final target must be sum of all nums / 2 = M. The problem becomes, can we select some numbers to sum up to M. Note there is no negative numbers, if some sum up to M, it won't be using all numbers.
Define dp[i][j], it means using some numbers from the first i numbers, can it sum up to j.

For initialization, dp[i][nums[i-1]] = true, means only selecting self in the set. Note that, acutally all dp[i][nums[0]] to dp[i][nums[i-1]] are true, but former numbers can be carried over by transfer function.

There is no transfer function from dp[i][j] and dp[i][j-1]. As we don't know what set of nums are used.
But there is transfer function from dp[i][j] = dp[i-1][j]. That means, either use the new num, or not use the new num.
dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]

Time Complexity: O(N*M);

## Java Code
<pre>
<code>
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int M = sum / 2;
        int N = nums.length;
        // dp[i][j] means, selecting some numbers from first i nums, can it sum up to j.
        // Init:
        //   dp[i][num] = true 
        // Transfer:
        //   dp[i][j] = dp[i-1][j] || dp[i-1][j-num[i-1]]
        boolean[][] dp = new boolean[N+1][M+1];
        for (int i = 1; i <= N; ++i) {
            if (nums[i-1] <= M) {
                dp[i][nums[i-1]] = true;      // If only one num: nums[i]
            }
            for (int j = 1; j <= M; ++j) {
                if (dp[i-1][j]) {             // If didn't use nums[i-1]
                    dp[i][j] = true;
                    continue;
                }
                if (j-nums[i-1] >= 0) {        // If use nums[i-1]
                    if (dp[i-1][j-nums[i-1]]) {
                        dp[i][j] = true;
                        continue;
                    }
                }
            }
        }
        return dp[N][M];
    }
}
</code>
</pre>

## BFS like

Like BFS, add all possible sums in a set.
Round 1: add first num in the set
Round 2: add the newNum, and all newNum + round1 nums in the set
Round N: repeat above
Until there is a num equal to target.

TimeComplexity:
Like all combinations, seems exponential?

## Java Code
<pre>
<code>
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int M = sum / 2;
        int N = nums.length;

        // having a set to record all possible sums. Gradually utilizing more and more nums
        HashSet<Integer> sums = new HashSet<>();
        for (int num : nums) {
            HashSet<Integer> sumsCopy = new HashSet<>(sums);
            sums.add(num);
            for (int copy : sumsCopy) {
                sums.add(copy + num);
            }
            if (sums.contains(M)) {
                return true;
            }
        }
        return false;
    }
}
</code>
</pre>