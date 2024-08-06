---
date:   2024-08-06
---

# Leetcode 875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

## Brute force
Try all possible k in the range of 1 and max(piles). Use the minimum k that satisfy the requirement.

## Binary search
Try all possible k in the range of [1, max(piles)]. From small to large, it needs to find the smallest value to satisfy the hour requirement.

That means, in the final range [left, (right)left+1], left should satify, while left+1 doesn't.

Note that, if k is larger, then it's easier to satisfy the h requirement.

## Java Code
<pre>
<code>
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxK = piles[0];
        for (int num : piles) {
            if (num > maxK) {
                maxK = num;
            }
        }
        int l = 1, r = maxK;
        while (l < r) {
            int mid = l + (r-l)/2;
            int hour = 0;
            for (int pile : piles) {
                hour += (pile + mid - 1) / mid;
            }
            if (hour <= h) {   // if mid value satisfy
                r = mid;
            } else {  // if mid value doesn't satisfy
                l = mid+1;
            }
        }
        // l == r;
        int hour = 0;
        for (int pile : piles) {
            hour += (pile + r - 1) / r;
        }
        if (hour <= h) {
            return r;
        }
        return -1;
    }
}
</code>
</pre>
