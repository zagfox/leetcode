---
date:   2024-07-31
---

# Leetcode 50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

## Divide and Conquer
Transition pow(x, n) to the problem of pow(x, n/2) recursively.

Needs to pay attention to the negative case, -3 / 2 = -1.

## Java Code
<pre>
<code>
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else if (n == -1) {
            return 1.0 / x;
        }
        if (n % 2 == 1) {
            double tmp = myPow(x, n/2);
            if (n > 0) {
                return x * tmp * tmp;
            } else {
                // e.g -3 / 2 = -1, mod 1.
                return 1/x * tmp * tmp;
            }
        } else {
            double tmp = myPow(x, n/2);
            return tmp * tmp;
        }
    }
}
</code>
</pre>
