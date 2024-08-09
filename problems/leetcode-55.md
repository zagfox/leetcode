---
date:   2024-08-09
---

# Leetcode 55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

## One scan for reachable
Starting from position[0], check where it can reach to based on its jump range. Mark reachable points. Then go to next posistion. This works because it cannot jump back.

## Java Code
<pre>
<code>
class Solution {
    public boolean canJump(int[] nums) {
        int N = nums.length;
        boolean[] reachable = new boolean[N];
        reachable[0] = true;
        for (int i = 0; i < N; ++i) {
            if (reachable[i]) {
                for (int j = 1; j <= nums[i]; ++j) {
                    int pos = i + j;
                    if (pos < N) {
                        reachable[pos] = true;
                    }
                }
            }
        }
        return reachable[N-1];
    }
}
</code>
</pre>

## not using additional space
There is a way to avoid the additional space
https://www.cnblogs.com/grandyang/p/4371526.html
