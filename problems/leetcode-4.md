---
date:   2024-08-10
---

# Leetcode 4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

## Binary search
As the problem ask log(m+n) complexity. 

If (m+n) is odd, only one number is the mean. If there is a combined array, it's the number at position (m+n)/2, index from 0.
If (m+n) is even, then it needs two number to calculate the mean. If there is a combined array, they are the numbers at positions (m+n-1)/2 and (m+n)/2, index from 0.

Then the problem converts to "how to find K's indexed number in num1 and num2 merged array?"

Checking
https://www.cnblogs.com/grandyang/p/4465932.html
only roughly get the idea.


## Java Code
<pre>
<code>


</code>
</pre>