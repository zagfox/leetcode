---
date:   2024-07-25
---

# Leetcode 11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

## Brute force
Try all combinations. Time complexity O(N^2).

## Two pointer with greedy
Suppose we are already choose two lines at (i, j), and hight[i] < hight[j]. And we have a temp max at (j-i) * hight[i]. 

It is impossible to find the max answer at (i, k), where k < j. Because k < j, and hight is <= hight[i]. So we can branch out these cases.

## Java Code
<pre>
<code>
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int output = 0;
        while (i < j) {
            int tmp = (j-i) * Math.min(height[i], height[j]);
            if (tmp > output) {
                output = tmp;
            }
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return output;
    }
}
</code>
</pre>
