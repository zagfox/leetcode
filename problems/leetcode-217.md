---
date:   2024-06-18
---

# Leetcode 217: Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

## Hashmap
Use a hash map to store frequency of numbers.


## Java Code
<pre>
<code>
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> distinctNumbers = new HashSet<>();
        for (int num : nums) {
            if (distinctNumbers.contains(num)) {
                return true;
            }
            distinctNumbers.add(num);
        }
        return false;
    }
}
</code>
</pre>