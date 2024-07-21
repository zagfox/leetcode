---
date:   2024-07-20
---

# Leetcode 75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

## Counting
Count how many 0, 1 and 2. Then directly set the array with those numbers.

## Array swap
It requires to sort it in place. Some kind of swap is needed. Solution has two rounds
Round 1
  1. Have two pointers at head and tail
  2. Head pointer move to the first point that's not 0, tail pointer move to the first point that's 0
  3. Swap head and tail pointer, repeat step 2.
After this operation, all 0 are at the front of the array.

Round 2, similar with first round, but moving number 2 to the back of the array.

## Java Code
<pre>
<code>
class Solution {
    public void sortColors(int[] nums) {
        // First round, move 0 to the front
        int p = 0, q = nums.length - 1;
        while (p < q) {
            while (p < nums.length && nums[p] == 0) {
                ++p;
            }
            while (q >= 0 && nums[q] != 0) {
                --q;
            }
            if (p >= q) {
                break;
            }
            int tmp = nums[p];
            nums[p] = nums[q];
            nums[q] = tmp;
        }
        // Second round, move 2 to the back
        p = 0;
        q = nums.length - 1;
        while (p < q) {
            while (p < nums.length && nums[p] != 2) {
                ++p;
            }
            while (q >= 0 && nums[q] == 2) {
                --q;
            }
            if (p >= q) {
                break;
            }
            int tmp = nums[p];
            nums[p] = nums[q];
            nums[q] = tmp;
            --q;
        }
    }
}
</code>
</pre>

## One-pass array Swap
Instead doing it with 2 rounds, just one round to move all 0 to front and 2 to the back.
  1. Having two pointers at head and tail
  2. Iterate the array sequentialy, if hit 0, swap it with head, head ptr + 1 
                                    if hit 2, swap it with tail, tail ptr - 1

## Java Code
<pre>
<code>
class Solution {
    public void sortColors(int[] nums) {
        int p = 0, q = nums.length - 1;
        for (int i = 0; i <= q;) {
            if (nums[i] == 0) {
                // Avoid the case that i stuck at same place
                if (i == p) {
                    ++i;
                    ++p;
                    continue;
                }
                nums[i] = nums[p];
                nums[p] = 0;
                ++p;
                continue;
            }
            if (nums[i] == 2) {
                nums[i] = nums[q];
                nums[q] = 2;
                --q;
                continue;
            }
            ++i;
        }
    }
}
</code>
</pre>
