---
date:   2024-07-22
---

# Leetcode 1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Brute Force
The straightforward way is double-looping. For each number, iterate all other numbers,
if those 2 add up to the target number. Return their indexes.
Time complexity: O(N^2)

## Sorting
Sorting the input array can help. After sorting, we can use two pointers approach. That one pointer at the head and the other at the end, moving those 2 pointers towards the middle until we find a solution. Extra work is needed to find the index of the number. The sorting won't keep the number indexes.
Time complexity: O(N*log(N))

## Hash Table
Having a first round of iteration of those numbers, keep track of the mapping from number to its index. As each input just have <b>exactly one solution</b>. It is okay to overwrite the index if there are duplicates. Because the second round of iteration will start from beginning, and if the solution are composed of two duplicates number, the iterator is at the first duplicate while the hashmap returns the last duplicate.
Time complexity: O(N) <br>
Space complexity: O(N) <br>

## Java Code
<pre>
<code>
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // First round of iteration to create mapping from num to index.
        Map<Integer, Integer> numToIndex = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            numToIndex.put(nums[i], i);
        }
        // Second round of iteration to find the pair of (num, target-num)
        for (int i = 0; i < nums.length; ++i) {
            Integer j = numToIndex.get(target - nums[i]);
            if (j == null || i == j) continue;
            return new int[]{i, j};
        }
        return null;
    }
}
</code>
</pre>
