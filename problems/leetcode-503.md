---
date:   2024-08-11
---

# Leetcode 503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
 
## Brute force
For every number, check its following numbers.
Complexity: O(N^2)

## Two pointer and using stack
Pointer p at the place that the number hasn't resolved
Using a stack to store the position of numbers that pending resolved. Start iteration from position 0, iterate for 2N iterations.
  1. if stack is non empty, check if number is larger than the stack top, if yes, record this answer, pop the stack and try for remaining of the number.
  2. now either stack is empty or curr <= stack.peek. If this number is not resolved, add it to the stack.Finally, add this number's position to the stack.

Run this iteration for 2 rounds, all should have an answer unless for the largest number. Mark those as -1.


## Java Code
<pre>
<code>
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int N = nums.length;
        Stack<Integer> posStack = new Stack<>();
        int[] output = new int[nums.length];
        boolean[] resolved = new boolean[nums.length];
        for (int i = 0; i < 2*N; ++i) {
            int j = i % N;

            while (!posStack.isEmpty() && nums[j] > nums[posStack.peek()]) {
                int pos = posStack.pop();
                output[pos] = nums[j];
                resolved[pos] = true;
            }
            // now either stack is empty or the curr <= peek()
            if (!resolved[j]) {
                posStack.push(j);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (!resolved[i]) {
                output[i] = -1;
                resolved[i] = true;
            }
        }
        return output;
    }
}
</code>
</pre>
