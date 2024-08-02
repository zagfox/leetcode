---
date:   2024-06-18
---

# Leetcode 67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

## Big Int
Similar to the way that humans do large number sum. Start from the end of the number. Add them if exceed the limit, plus one to the carry bit. Note that the iteration sequence is from back of the int string to the beginning.


## Java Code
<pre>
<code>
class Solution {
    public String addBinary(String a, String b) {
        int aLength = a.length(), bLength = b.length();
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < Math.max(aLength, bLength); ++i) {
            int aBit = 0, bBit = 0;
            if (i < aLength) {
                aBit = Character.getNumericValue(a.charAt(aLength - 1 - i));
            }
            if (i < bLength) {
                bBit = Character.getNumericValue(b.charAt(bLength - 1 - i));
            }
            int sum = aBit + bBit + carry;
            if (sum % 2 == 0) {
                sb.append('0');
            } else {
                sb.append('1');
            }
            carry = sum / 2;
        }
        if (carry == 1) {
            sb.append('1');
        }
        return sb.reverse().toString();
    }
}
</code>
</pre>