---
date:   2024-06-14
---

# Leetcode 242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Hash Table
Fundamentally it require the two letters have the same char frequency. The solution is to keep track of 
the char frequency of the two letter using hash map.
Time complexity: O(N)

## Java Code
<pre>
<code>
class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> frequency = new HashMap<>();
        for(char c : s.toCharArray()) {
            frequency.put(c, frequency.getOrDefault(c, 0) + 1);
        }
        for (char c : t.toCharArray()) {
            frequency.put(c, frequency.getOrDefault(c, 0) - 1);
        }
        for (Map.Entry<Character, Integer> entry : frequency.entrySet()) {
            if (entry.getValue() != 0) {
                return false;
            }
        }
        return true;
    }
}
</code>
</pre>