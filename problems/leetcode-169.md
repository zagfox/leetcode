---
date:   2024-06-18
---

# Leetcode 169: Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

## Hash Map
Keeping a frequency map from element to counts. Then iterate on the frequency map to find the majority element.
Time Complexity: O(N)
Space Complexity: O(N)

## Sorting
Majority element definition is special, it has to appear more than ⌊n / 2⌋ times. After sorting, Checking the middle position will give us an answer.
Time Complexity: O(N*log(N))
Space Complexity: O(1)

## Moore Voting
This is a special algorithm. It makes use of the fact that the majority element appear more than ⌊n / 2⌋ times. And this problem guarnatees that such element exists. The idea is to "double delete" different elements. The left overs must be the majority element.

In detail, it scans the element list. 
1. Hit an element, assume it is the majority, giving it count 1.
2. Continue scan, if next element is the same, increment the count. 
3. If next element is different, decrement the count. If count goes 0, goes to #1.

Time Complexity: O(N)
Space Complexity: O(1)

## Java Code
<pre>
<code>
class Solution {
    public int majorityElement(int[] nums) {
        // Moore Voting algorithm
        int element = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                element = num;
                cnt = 1;
                continue;
            }
            if (num == element) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return element;
    }
}
</code>
</pre>