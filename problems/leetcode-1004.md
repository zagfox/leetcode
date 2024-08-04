---
date:   2024-08-04
---

# Leetcode 1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

## Recursion
When encounter 0, try both ways, one is to not convert, the other is to convert.

Can make use of memorization, that data[i] denote the max lengths of 1s if in the range of 
[nums[i], end]. But it didn't take into account of K.

## Sliding window
If such kind of long sequence of 1 exist, it must be a result of using those k flips all together.
Having a sliding window to denote the start of 1s and end of 1s while using at most k flips.

## Java Code
<pre>
<code>
class Solution {
    public int longestOnes(int[] nums, int k) {
        // Having a slinding window range [left, right] to mark the range of all 1s.
        int left = 0, right = 0;
        int maxLength = 0, flipped = 0;
        while (right < nums.length) {
            if (nums[right] == 1) {
                int length = right - left + 1;
                maxLength = Math.max(maxLength, length);
                ++right;
                continue;
            }
            // This position is 0. Two cases, one is that it can flip, the other
            // is that we used all flips.
            if (flipped < k) {
                ++flipped;
                int length = right - left + 1;
                maxLength = Math.max(maxLength, length);
                ++right;
                continue;
            } else {
                // move left boundary
                while (nums[left] == 1) {
                    ++left;
                }
                ++left;
                --flipped;
                continue;
            }
        }
        return maxLength;
    }
}
</code>
</pre>
