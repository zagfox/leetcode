---
date:   2024-08-01
---

# Leetcode 42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## Store left view
Think about the shape that can hold water as a bowl. At a right bar, it can see some of the left bars, while some are hidden. Those hidden ones are already calculated its holding capacity.
Scan the array left to right, and store the left side view at a position pos. And calculate holding water based on the current pos' bar, and the left side view.

The following solution works, though TLE.

## Java Code
<pre>
<code>
class Solution {
    public int calculate(int pos, LinkedList<Integer> visibleBars, int[] height) {
        if (visibleBars.size() <= 1) {
            return 0;
        }
        if (height[pos] <= height[visibleBars.getLast()]) {
            return 0;
        }
        int output = 0;
        int floor = height[visibleBars.getLast()];
        for (int i = visibleBars.size()-2; i >= 0; --i) {
            int barPos = visibleBars.get(i);
            if (Math.min(height[barPos], height[pos]) <= floor) {
                continue;
            }
            output += (Math.min(height[barPos], height[pos]) - floor) * (pos - barPos -1);
            floor = height[barPos];
        }
        return output;
    }
    public int trap(int[] height) {
        // Think about all trap as bowl shape, from bowl's right edge. Only record left bars that
        // are visible.
        LinkedList<Integer> visibleBars = new LinkedList<>();
        int output = 0;
        for (int i = 0; i < height.length; ++i) {
            //System.out.println("Position " + i);
            output += calculate(i, visibleBars, height);
            //System.out.println("Final output is " + output);
            while (!visibleBars.isEmpty() && height[visibleBars.getLast()] <= height[i]) {
                // remove all bars that are hidden behind.
                visibleBars.removeLast();
            }
            visibleBars.add(i);
        }
        return output;
    }
}
</code>
</pre>


## Dynamic programing
TBD