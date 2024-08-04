---
date:   2024-08-04
---

# Leetcode 443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

## One scan
It requires to store the output in the same char array. After compression, the output must be smaller than the original one. It needs to use two pointer, one point at the original array, the other point at the output array.

## Java Code
<pre>
<code>
class Solution {
    public int compress(char[] chars) {
        // p points at original array, q points at new array
        int p = 0, q = 0;
        while (p < chars.length) {
            char ch = chars[p];
            int cnt = 0;
            while (p < chars.length) {
                if (chars[p] != ch) {
                    break;
                }
                ++p;
                ++cnt;
            }
            chars[q] = ch;
            ++q;
            if (cnt == 1) {
                continue;
            }

            String cntStr = Integer.toString(cnt);
            for (int i = 0; i < cntStr.length(); ++i) {
                chars[q] = cntStr.charAt(i);
                ++q;
            }
        }
        return q;
    }
}
</code>
</pre>
