---
date:   2024-07-31
---

# Leetcode 1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

## Left Right pointer
Having two pointers, left and right. Trying to move to the middle
  1. Left and right move to the first () it encoutner
  2. If left is ), remove and move to next, until it hit (
  3. If left is (, move right until it hit ), if not, remove the left
Record removed positions, and reconstruct the string.

But, this assumes the pair is always at the larger range, it cannot handle ()().

## Recursion
Seems very complicated.

## Two scan
First scan, left to right.
  1. If encounter (, add count.
  2. If encounter ), minus count. But if count is already 0, move ).
Second scan, right to left.

Overall, first scan, removes invalid ), and the second scan remove invalid (.

## Java Code
<pre>
<code>
class Solution {
    public String minRemoveToMakeValid(String s) {
        HashSet<Integer> removed = new HashSet<>();
        int leftCount = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++leftCount;
            } else if (s.charAt(i) == ')') {
                if (leftCount > 0) {
                    --leftCount;
                } else {
                    removed.add(i);
                }
            }
        }
        int rightCount = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            if (s.charAt(i) == ')') {
                ++rightCount;
            } else if (s.charAt(i) == '(') {
                if (rightCount > 0) {
                    --rightCount;
                } else {
                    removed.add(i);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (!removed.contains(i)) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
</code>
</pre>

## Use stack
Can use a stack to just scan once
https://www.cnblogs.com/grandyang/p/15515997.html