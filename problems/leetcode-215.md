---
date:   2024-08-03
---

# Leetcode 215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

## Sort
Sort and select.

## Priority Queue
A min heap, only keep k elements. 

## Quick sort style
Do a quick sort on the array, partition the array such that there is a pivot value, and left side are values larger than pivot, and right side are values smaller than pivot.

I refer to this for quick sort
https://www.runoob.com/w3cnote/quick-sort-2.html
Didn't use swap, but assignment. But it's better to think in the way that pivotVal is always swapped.

## Java Code
<pre>
<code>
class Solution {
    // Find k's largest in the [left, right] range.
    public int find(int[] nums, int leftBound, int rightBound, int k) {
        if (leftBound == rightBound) {
            return nums[leftBound];
        }
        // Select right bound value as the pivot.
        int pivotVal = nums[rightBound];
        // r is pointing at pivotVal
        int l = leftBound, r = rightBound;
        // Partition the range, such that nums > pivot is on the left, nums <= pivot is on the right.
        while (l < r) {
            while (l < r && nums[l] >= pivotVal) {
                ++l;
            }
            nums[r] = nums[l];
            
            while (l < r && nums[r] <= pivotVal) {
                --r;
            }
            nums[l] = nums[r];
        }
        if (r == k-1) {
            return pivotVal;
        } else if (r < k-1) {
            // find on the right
            return find(nums, r+1, rightBound, k);
        } else {
            return find(nums, leftBound, r-1, k);
        }

    }
    public int findKthLargest(int[] nums, int k) {
        return find(nums, 0, nums.length-1, k);
    }
}
</code>
</pre>
