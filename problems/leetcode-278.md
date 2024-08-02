---
date:   2024-06-18
---

# Leetcode 278. First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

## Binary Search
If one version is bad, all the remaining versions are bad. The idea is binary search. It asked for the first bad version. After selecting the middle point:
1. If middle point is good, continue searching in the range [mid+1, right]
2. If middle point is bad, check if middle point's left is good, return middle point in this case.
   Other wise, continue searching in the range [left, mid-1]

## Java Code
<pre>
<code>
public class Solution extends VersionControl {
    // Left and right boundary is inclusive.
    public int bSearch(int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right-left)/2;
        if (!isBadVersion(mid)) {
            return bSearch(mid+1, right);
        } else {
            if (mid == 1) return mid;
            if (!isBadVersion(mid-1)) return mid;
            return bSearch(left, mid-1);
        }
    }
    public int firstBadVersion(int n) {
        return bSearch(1, n);
    }
}
</code>
</pre>