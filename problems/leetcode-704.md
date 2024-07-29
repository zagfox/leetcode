---
date:   2024-06-15
---

# Leetcode 704: Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

# Binary Search
The input array is already sorted, the binary search algorithm makes use of this, combined with divide and conquer idea. When searching in the range [i...j], choose the middle of the array, if the middle value is larger than the target, then the target is on the left side; otherwise, target is on the right side.

Time complexity: O(log(N))

## Java Code
<pre>
<code>
class Solution {
    // left and right boundary is inclusive.
    public int bSearch(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        // If left + right is odd, floor to small number.
        int mid = left + (right-left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bSearch(nums, target, mid+1, right);
        } else {
            return bSearch(nums, target, left, mid-1);
        }
    }
    public int search(int[] nums, int target) {
        return bSearch(nums, target, 0, nums.length-1);
    }
}
</code>
</pre>