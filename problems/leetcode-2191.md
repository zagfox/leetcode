---
date:   2024-08-09
---

# Leetcode 2191. Sort the Jumbled Numbers

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.

## Customized sorting comparator
Store original number and converted one in a new class Entry. Sort the entry with customized comparator. Then output it in the result.

## Java Code
<pre>
<code>
class Solution {
    class Entry{
        int original;
        int converted;
        public Entry(int original, int converted) {
            this.original = original;
            this.converted = converted;
        }
    }
    public int[] sortJumbled(int[] mapping, int[] nums) {
        Entry[] entries = new Entry[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            int converted = 0;
            int multiply = 1;
            do {
                converted = mapping[num%10] * multiply;
                num /= 10;
                multiply *= 10;
            } while (num != 0);
            entries[i] = new Entry(nums[i], converted);
        }
        Arrays.sort(entries, new Comparator<Entry>(){
            public int compare(Entry a, Entry b) {
                return Integer.compare(a.converted, b.converted);
            }
        });
        int[] output = new int[nums.length];
        for (int i = 0; i < entries.length; ++i) {
            output[i] = entries[i].original;
        }
        return output;
    }
}
</code>
</pre>

## Ordered map
Use converted int as map key, store a vector of original nums.
