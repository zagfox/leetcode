---
date:   2024-07-16
---

# Leetcode 33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

## Modified binary search

The problem requires to solve within O(log n), which indicates it uses binary search like solution. But it's different, there are two possibility
1. The range didn't contain the cliff point, so it's increasing. left < right.
2. The range contains the cliff point, the it's first increasing, then cliff, then increasing. left > right.

The algorithm should consider both cases.

## Java Code
<pre>
<code>
class Solution {
    // Search in the range [left, right], both left and right are included.
    public int bSearch(int[] nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        if (left == right) {
            if (nums[left] == target) {
                return left;
            }
            return -1;
        }
        int mid = left + (right-left)/2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] > nums[mid]) {          // If cliff on the left
            if (nums[mid] < target && target <= nums[right]) {
                // then right side is well sorted
                return bSearch(nums, mid+1, right, target);
            } else {
                return bSearch(nums, left, mid-1, target);
            }
        } else if (nums[mid] > nums[right]) {  // cliff on the right
            // left side is well sorted
            if (nums[left] <= target && target < nums[mid]) {
                return bSearch(nums, left, mid-1, target);
            } else {
                return bSearch(nums, mid+1, right, target);
            }
        } 
        // no cliff, fallback to normal binary search.
        if (nums[left] <= target && target < nums[mid]) {
            return bSearch(nums, left, mid-1, target);
        } else {
            return bSearch(nums, mid+1, right, target);
        }
    }
    public int search(int[] nums, int target) {
        return bSearch(nums, 0, nums.length-1, target);   
    }
}
</code>
</pre>
