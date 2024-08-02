---
date:   2024-06-18
---

# Leetcode 383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

## Hash Map
The idea is to iterate on the magazine and create a map from char->frequency. Then iterate on the ransomNote, decreasing the map's value for each char. And if the final map are all >= 0. It can be constructed.

## Java Code
<pre>
<code>
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : magazine.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0)+1);
        }
        for (char c : ransomNote.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) - 1);
        }
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            if (entry.getValue() < 0) {
                return false;
            }
        }
        return true;
    }
}
</code>
</pre>