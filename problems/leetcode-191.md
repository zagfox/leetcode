---
date:   2024-08-01
---

# Leetcode 191. Number of 1 Bits

Write a function that takes the binary representation of a positive integer and returns the number of set bits it has (also known as the Hamming weight).

## Mod 2 and right move
Every time, mod the value with 2, then bit wise right move, which means divide by 2.

## Java Code
<pre>
<code>
class Solution {
    public int hammingWeight(int n) {
        int val = n;
        int cnt = 0;
        while (val != 0) {
            cnt += val % 2;
            val = val >> 1;
        }
        return cnt;
    }
}
</code>
</pre>
