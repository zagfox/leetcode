---
date:   2024-08-10
---

# Leetcode 1395. Count Number of Teams

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

## Brute force
Try all combinations, check if that satisfy the requirement.
O(N^3)

## Left & Right comparison
For any position, check its left for all ratings less than it, and check its right for all numbers larger than it. Then multiple those 2, it is the combination if using this number.

O(N^2)

## Java Code
<pre>
<code>
class Solution {
    public int numTeams(int[] rating) {
        int output = 0;
        for (int j = 0; j < rating.length; ++j) {
            // left side smaller, left side larger, right side smaller, right side larger.
            int a = 0, b = 0, c = 0, d = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++a;
                } else if (rating[i] > rating[j]) {
                    ++b;
                }
            }
            for (int k = j+1; k < rating.length; ++k) {
                if (rating[k] < rating[j]) {
                    ++c;
                } else if (rating[k] > rating[j]) {
                    ++d;
                }
            }
            output += a * d;
            output += b * c;
        }
        return output;
    }
}
</code>
</pre>
