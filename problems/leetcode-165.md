---
date:   2024-08-01
---

# Leetcode 165. Compare Version Numbers

Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

## String split and compare left to right
Use '.' to split the string into a list. Compare two list from left to right, if length exceed one of the list, treat it as 0. If encounter one not equal, can return the result.

## Java Code
<pre>
<code>
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] tokens1 = version1.split("\\.");
        String[] tokens2 = version2.split("\\.");
        for (int i = 0; i < Math.max(tokens1.length, tokens2.length); ++i) {
            int val1 = 0, val2 = 0;
            if (i < tokens1.length) {
                val1 = Integer.parseInt(tokens1[i]);
            }
            if (i < tokens2.length) {
                val2 = Integer.parseInt(tokens2[i]);
            }
            if (val1 < val2) {
                return -1;
            }
            if (val1 > val2) {
                return 1;
            }
        }
        return 0;
    }
}
</code>
</pre>
