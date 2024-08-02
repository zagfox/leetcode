---
date:   2024-06-21
---

# Leetcode 70: Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Recursion
Suppose we define a function f(k) to calculate the number of distinct ways to clib k steps. Inside function(k), it calls f(k-1) and f(k-2) to calculate itself. This is recursion.

## Recursion with memorization
There is duplicated calculation in recursion. When calculating f(k-1), it calculate f(k-2) and f(k-3), but f(k-2) is also calcuated for f(k). Thus, one way is to remember those f(k) and hold them in memory.

## Dynamic Programing
Recursion with memorization is a top down approach, getting f(k) first, then gradually goes to f(1). Dynamic programming is a bottom up approach, calculate f(1) first, then gradually pushes to f(k).

## DP Java Code
<pre>
<code>
class Solution {
    public int climbStairs(int n) {
        int[] ways = new int[n+1];
        ways[0] = 1;
        ways[1] = 1;
        for (int i = 2; i <= n; ++i) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n];
    }
}
</code>
</pre>
