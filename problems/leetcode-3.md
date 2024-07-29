---
date:   2024-06-18
---

# Leetcode 3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

## One Pass
Have two pointers, p and q, representing a substring [p,q]. Both points at the start of the candidate substring. Moving q gradually, record the last seen position of the chars. If q hits an already seen character, record the substring length. And move p to the +1 place of the last occurance of the newly seen character.

## Java Code
<pre>
<code>
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        int p = 0, q = 0;
        int maxLength = 0;
        HashMap<Character, Integer> lastSeen = new HashMap<>();
        while (q < s.length()) {
            char c = s.charAt(q);
            if (!lastSeen.containsKey(c) || lastSeen.get(c) < p) {
                int length = q - p + 1;
                maxLength = Math.max(maxLength, length);
            } else {
                int length = q - lastSeen.get(c);
                maxLength = Math.max(maxLength, length);
                p = lastSeen.get(c) + 1;
            }
            lastSeen.put(s.charAt(q), q);
            ++q;
        }
        return maxLength;
    }
}
</code>
</pre>