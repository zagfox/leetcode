---
date:   2024-07-22
---

# Leetcode 8. String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

## String handling
Iterate on the string chars, handle them in sequence.

## Java Code
<pre>
<code>
class Solution {
    public int myAtoi(String s) {
        long number = 0;
        int pos = 0;
        int sign = 1;
        while (pos < s.length() && s.charAt(pos) == ' ') {
            ++pos;
        }
        if (pos < s.length()) {
            if (s.charAt(pos) == '+') {
                sign = 1;
                ++pos;
            } else if (s.charAt(pos) == '-') {
                sign = -1;
                ++pos;
            }
        }
        while (pos < s.length() && s.charAt(pos) == '0') {
            ++pos;
        }
        while (pos < s.length()) {
            int digit = s.charAt(pos) - '0';
            if (digit < 0 || digit > 9) {
                break;
            }
            number *= 10;
            number += digit;
            if (number*sign > Integer.MAX_VALUE || number*sign < Integer.MIN_VALUE) {
                break;
            }
            ++pos;
        }
        number *= sign;
        if (number > Integer.MAX_VALUE) {
            number = Integer.MAX_VALUE;
        }
        if (number < Integer.MIN_VALUE) {
            number = Integer.MIN_VALUE;
        }
        return (int)number;
    }
}
</code>
</pre>
