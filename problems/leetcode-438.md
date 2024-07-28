---
date:   2024-07-27
---

# Leetcode 438. Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Brute force
For all start point, check its later M chars (M is the length of target string). Check if letter combination is the same as the target.
Time Complexity: O(N*M)

## Sliding Window
There are duplicate computation in the brute force approach. Instead of recomputing all M chars, it can remove the previous char and include the new char.

## Java Code
<pre>
<code>
class Solution {
    public boolean allMatch(int[] freqDiffs) {
        for (int diff : freqDiffs) {
            if (diff != 0) {
                return false;
            }
        }
        return true;
    }
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> output = new LinkedList<>();
        // Frequency diffs of 26 letters, computed by s's sliding window - p's frequency.
        int[] freqDiffs = new int[26];
        for (int i = 0; i < s.length() && i < p.length(); ++i) {
            ++freqDiffs[s.charAt(i)-'a'];
        }
        for (char ch : p.toCharArray()) {
            --freqDiffs[ch-'a'];
        }
        if (allMatch(freqDiffs)) {
            output.add(0);
        }
        for (int i = 1; i+p.length() <= s.length(); ++i) {
            char prevChar = s.charAt(i-1);
            --freqDiffs[prevChar-'a'];
            char newChar = s.charAt(i+p.length()-1);
            ++freqDiffs[newChar-'a'];
            if (allMatch(freqDiffs)) {
                output.add(i);
            }
        }
        return output;
    }
}
</code>
</pre>
