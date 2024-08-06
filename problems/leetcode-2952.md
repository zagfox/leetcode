---
date:   2024-08-06
---

# Leetcode 2952. Minimum Number of Coins to be Added

You are given a 0-indexed integer array coins, representing the values of the coins available, and an integer target.

An integer x is obtainable if there exists a subsequence of coins that sums to x.

Return the minimum number of coins of any value that need to be added to the array so that every integer in the range [1, target] is obtainable.

A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.

## Special bucket
Use special bucket of range 1 ... target, suppose its 10. 
If there is number 1 we can only form
    1 ....
If there is one more number 3, Then we can add 3 to all previous round of letter.
    1 (2) 3 4 ...
If there is another number, we can add it to all previous round of letter

And for each round, choose the number that cannot be formed and add to the coin set. It's arguable that there are other ways to form that number. But I think there can be some kind of proof to show that always using that coin is the min-count way.
                 
This solution works. But TLE in leetcode.

## Java Code
<pre>
<code>
class Solution {
    public void updateBuckets(boolean[] buckets, int coin) {
        for (int i = buckets.length-1; i >= 0; --i) {
            if (buckets[i] == false) {
                continue;
            }
            int val = i + coin;
            if (val >= buckets.length) {
                continue;
            }
            buckets[val] = true;
        }
    }
    public int minimumAddedCoins(int[] coins, int target) {
        Arrays.sort(coins);
        boolean[] buckets = new boolean[target+1];
        buckets[0] = true;
        for (int coin : coins) {
            updateBuckets(buckets, coin);
        }
        int output = 0;
        for (int i = 1; i <= target; ++i) {
            if (buckets[i] == false) {
                updateBuckets(buckets, i);
                ++output;
            }
        }
        return output;
    }
}

</code>
</pre>

## Greedy, range, etc
https://github.com/doocs/leetcode/blob/main/solution/2900-2999/2952.Minimum%20Number%20of%20Coins%20to%20be%20Added/README.md