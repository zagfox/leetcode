---
date:   2024-06-18
---

# Leetcode 238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

## Precomputation
Have two set of precomputation, leftProduct and rightProduct. leftProduct[i] is the product of all numbers in range [0, i]. And rightProduct[i] is the product of all numbers in range [i, last].
And result[i] = leftProduct[i-1] * rightProduct[i+1]

## Java Code
<pre>
<code>
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length;
        int[] leftProduct = new int[N];
        int[] rightProduct = new int[N];
        for (int i = 0; i < N; ++i) {
            if (i == 0) {
                leftProduct[0] = nums[0];
            } else {
                leftProduct[i] = leftProduct[i-1] * nums[i];
            }
        }
        for (int i = N-1; i >= 0; --i) {
            if (i == N-1) {
                rightProduct[i] = nums[i];
            } else {
                rightProduct[i] = rightProduct[i+1] * nums[i];
            }
        }

        int[] result = new int[N];
        for (int i = 0; i < N; ++i) {
            int left = 1;
            if (i > 0) {
                left = leftProduct[i-1];
            }
            int right = 1;
            if (i < N-1) {
                right = rightProduct[i+1];
            }
            result[i] = left * right;
        }
        return result;
    }
}
</code>
</pre>