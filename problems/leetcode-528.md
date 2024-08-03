---
date:   2024-08-03
---

# Leetcode 528. Random Pick with Weight

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 
## Cumulative boundary and random
Create a cumulative boundary for each weights. For example, if weights are [1, 2, 3], then the cumulative boundary are [1, 3, 6]
Then create a random integer x in the range of [0, 6). 
Iterate all boundary, if boundary > x, then break out.

It can be speed up with binary search
x is   : 0     1 2      3 4 5
select : 0      1         2

The binary search is very tricky.

## Java Code
<pre>
<code>
class Solution {
    int[] boundary;
    int total;
    Random rand;

    public Solution(int[] w) {
        boundary = new int[w.length];
        int sum = 0;
        for (int i = 0; i < w.length; ++i) {
            sum += w[i];
            boundary[i] = sum;
        }
        total = sum;

        rand = new Random();
    }
    
    // Linear search
    public int pickIndexLinear() {
        int x = rand.nextInt(total);
        int i = 0;
        for (; i < boundary.length; ++i) {
            if (boundary[i] > x) {
                return i;
            }
        }
        return -1;
    }

    // Binary search
    public int pickIndex() {
        int x = rand.nextInt(total);
        int l = 0, r = boundary.length-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (boundary[mid] <= x) {
                l = mid+1;
                continue;
            } else {
                r = mid;
            }
        }
        // l == r
        return r;
    }
}
</code>
</pre>
