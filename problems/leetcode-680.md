---
date:   2024-07-30
---

# Leetcode 680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

## Two pointer
Have two pointer, one at the left, the other at the right. Check if left and right are the same, if not, try to delete one of them to check if it can make a left/right match. This indicates delete quota left. If delete still cannot work, return false.

Note that in the case of not match, both left advance, and right advance case needs to be tried.

## Java Code
<pre>
<code>
class Solution {
    public boolean valid(String s, int l, int r, int deleteQuota) {
        if (l >= r) {
            return true;
        }
        if (s.charAt(l) == s.charAt(r)) {
            return valid(s, l+1, r-1, deleteQuota);
        }
        if (deleteQuota == 0) {
            return false;
        }
        --deleteQuota;
        if (valid(s, l+1, r, deleteQuota)) {
                return true;
        }
        if (valid(s, l, r-1, deleteQuota)) {
                return true;
        }
        return false;
    }
    public boolean validPalindrome(String s) {
        return valid(s, 0, s.length()-1, 1);
    }
}
</code>
</pre>
