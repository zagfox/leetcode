---
date:   2024-08-09
---

# Leetcode 121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Brute force
O(N^2) to iterate all options.

## Keep max value in an array
Use maxValue[i] to denote the max value in the range [i, last].
Then for each value at i, the max profit is maxValue[i] - value[i].

## Iterate from back to front
Such that there is no need to keep additional array for the max value.

## Java Code
<pre>
<code>
class Solution {
    public int maxProfit(int[] prices) {
        int N = prices.length;
        if (N == 0) return 0;

        int max = prices[N-1];
        int maxProfit = 0;
        for (int i = N-2; i >= 0; --i) {
            if (max - prices[i] > maxProfit) {
                maxProfit = max - prices[i];
            }
            if (prices[i] > max) {
                max = prices[i];
            }
        }
        return maxProfit;
    }
}
</code>
</pre>