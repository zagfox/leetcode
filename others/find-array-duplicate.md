---
date:   2024-07-16
---

# Find Array Duplicate

There is a length N+1 array, it can only contain numbers from 1 to N. How to find a number that duplicate? There can be multiple duplicates. And one number can duplicate multiple times.

Example, N = 3.
[3, 2, 1, 1]
[1, 2, 3, 1]
[2, 2, 2, 2]

## Move to index based position
If the number is sorted, and suppose there is only one duplicate, then the final array should look like [1, 2, 3, x]. That the first N elements numeric value is index+1. And the last element is the duplicate.

Based on this idea, the way to swap element. From left to right, when encounter an element, swap it to the position it should goes to. As duplicate exist, during the process, it must occur that one number is the same with the number on the swapped to position.

## Java Code
<pre>
<code>
class Solution {
  public static int FindDuplicate(int[] nums, int N) {
    for (int i = 0; i < nums.length;) {
      int num = nums[i];
      if (num == i+1) {
        ++i;
        continue;
      }
      int other = nums[num-1];
      if (num == other) {
        return num;
      }
      // Do the swap
      nums[i] = other;
      nums[num-1] = num;
    }
    return nums[N];
  }

  public static void main(String[] args) {
    int[] test1 = {1, 2, 3, 1};
    int dup = FindDuplicate(test1, 3);
    System.out.println("test1: " + dup);
    int[] test2 = {2, 2, 2, 2};
    dup = FindDuplicate(test2, 3);
    System.out.println("test2: " + dup);

    int[] test3 = {3, 2, 1, 1};
    dup = FindDuplicate(test3, 3);
    System.out.println("test3: " + dup);
  }
}
</code>
</pre>

## Quick / Slow pointer
The idea is to imagine it as a linked list. That each number points to array[number]. 
TBD: this doesn't work if duplicate is at index 0.