---
date:   2024-06-18
---

# Leetcode 409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

## HashMap
Use a hash map to store the frequency of chars. Then mathmatically, try substracting all pairs of chars. And finally, if there is some chars left, +1 to the final result and make that char the center of the palindrome.

## Java Code
<pre>
<code>
class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        int longest = 0;
        boolean leftOver = false;
        for (int cnt : freq.values()) {
            if (cnt % 2 == 1) {
                leftOver = true;
            }
            longest += cnt / 2 * 2;
        }
        if (leftOver) {
            longest += 1;
        }
        return longest;
    }
}
</code>
</pre>