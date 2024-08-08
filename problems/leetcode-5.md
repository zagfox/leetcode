---
date:   2024-07-24
---

# Leetcode 5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

## Brute force
Try all combination, check if they are palindrome. Each check is also O(N) because it iterate the subsequence.

TimeComplexity: O(N^3)

## Central expansion
Choose a point as central of the palindrome, expand to its neighbors. There are 2N such center points, and each center check at most N chars.

TimeComplexity: O(N^2)

## Java Code
<pre>
<code>
class Solution {
    public String longest(String s, int left, int right) {
        if (s.charAt(left) != s.charAt(right)) {
            return s.substring(left, left+1);
        }
        while (left >= 0 && right < s.length()) {
            if (s.charAt(left) != s.charAt(right)) {
                break;
            }
            --left;
            ++right;
        }
        ++left;
        --right;
        return s.substring(left, right+1);
    }
    public String longestPalindrome(String s) {
        if (s.length() == 0) {
            return "";
        }
        String output = s.substring(0, 1);
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j <= i+1 && j < s.length(); ++j) {
                String tmp = longest(s, i, j);
                if (tmp.length() > output.length()) {
                    output = tmp;
                }
            }
        }
        return output;
    }
}
</code>
</pre>

## Manacher's Algorithm
TBD, advanced
O(N)