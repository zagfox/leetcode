---
date:   2024-08-03
---

# Leetcode 88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

## n-way merge
Use some extra space, do the N-way merge.

## Java Code
<pre>
<code>
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] nums1Copy = Arrays.copyOf(nums1, m);
        int i = 0, j = 0, k = 0;
        while (i < m || j < n) {
            if (i >= m) {
                nums1[k] = nums2[j];
                ++k;
                ++j;
                continue;
            }
            if (j >= n) {
                nums1[k] = nums1Copy[i];
                ++k;
                ++i;
                continue;
            }
            if (nums1Copy[i] < nums2[j]) {
                nums1[k] = nums1Copy[i];
                ++k;
                ++i;
            } else {
                nums1[k] = nums2[j];
                ++k;
                ++j;
            }
        }
        return;
    }
}
</code>
</pre>

## 2 way merge, without extra space
Do the copy from back to front.