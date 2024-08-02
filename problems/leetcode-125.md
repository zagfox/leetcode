---
date:   2024-06-14
---

# Leetcode 125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

## Two Pointer
The idea is to have one pointer at the head and the other pointer at the end of the string. Moving those
two pointers towards the middle until they meet.
Time complexity: O(N)

## Java Code
<pre>
<code>
class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                ++i;
                continue;
            }
            if (!Character.isLetterOrDigit(s.charAt(j))) {
                --j;
                continue;
            }
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
}
</code>
</pre>