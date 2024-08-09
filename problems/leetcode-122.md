---
date:   2024-08-09
---

# Leetcode 122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

## Aggregate all diffs
The trader can profit on all the price increase among days. Iterate days and collect all inter-day gains.

## Java Code
<pre>
<code>
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for(int i = 0; i < prices.length-1; ++i) {
            if (prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
}
</code>
</pre>