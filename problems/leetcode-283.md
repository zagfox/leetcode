---
date:   2024-08-11
---

# Leetcode 283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

## One scan
During scan, add the position with 0 in a queue. When encounter a normal number, move it to the queue's head position, and add this number's position in the queue.

## Java Code
<pre>
<code>
class Solution {
    public void moveZeroes(int[] nums) {
        Queue<Integer> slots = new LinkedList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                slots.add(i);
                continue;
            }
            if (!slots.isEmpty()) {
                int pos = slots.poll();
                nums[pos] = nums[i];
                nums[i] = 0;
                slots.add(i);
            }
        }
    }
}
</code>
</pre>