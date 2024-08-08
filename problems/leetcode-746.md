---
date:   2024-08-07
---

# Leetcode 746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

## extending
Use minTotal[i] to record the minimal total cost to reach level i. minTotal[0] and [1] is known, extending it to other levels.

## Java Code
<pre>
<code>
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int N = cost.length;
        if (N == 1) {
            return cost[0];
        }
        int[] minTotal = new int[N];
        minTotal[0] = cost[0];
        minTotal[1] = cost[1];
        for (int i = 2; i < N; ++i) {
            minTotal[i] = Math.min(minTotal[i-2], minTotal[i-1]) + cost[i];
        }
        return Math.min(minTotal[N-2], minTotal[N-1]);
    }
}
</code>
</pre>
