---
date:   2024-08-03
---

# Leetcode 408. Valid Word Abbreviation

A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)

## One scan
Have two pointers, p pointing at the full word, q pointing at the abbreviation. If q encounter a number, get all numbers and let p goes past such number of chars.

## Java Code
<pre>
<code>
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int p = 0, q = 0;
        while (p < word.length() && q < abbr.length()) {
            if (Character.isDigit(abbr.charAt(q))) {
                if (abbr.charAt(q) == '0') {
                    return false;
                }
                int num = Character.getNumericValue(abbr.charAt(q));
                while (q+1 < abbr.length() && Character.isDigit(abbr.charAt(q+1))) {
                    num *= 10;
                    num += Character.getNumericValue(abbr.charAt(q+1));
                    ++q;
                }
                p += num;
                q += 1;
            } else {
                if (word.charAt(p) != abbr.charAt(q)) {
                    return false;
                }
                ++p;
                ++q;
            }
        }
        return p == word.length() && q == abbr.length();
    }
}
</code>
</pre>