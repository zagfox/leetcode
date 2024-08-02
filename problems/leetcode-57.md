---
date:   2024-06-18
---

# Leetcode 57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

## Algorithm
Interval list is a special data structure. The newly inserted one should merge with the existing ones, and keep the output also sorted by start interval. The algorithm is to find the first overlapping interval, and merge with the newly inserted one. Continue merging and insert the result to the list.

The problem doesn't require to modify intervals in place. Which makes the operation easier. If the problem gives a linkedList of interval, the solution involves more complex operations.

## Java Code
<pre>
<code>
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        LinkedList<int[]> output = new LinkedList<>();
        int start = newInterval[0], end = newInterval[1];
        boolean inserted = false;
        for (int[] interval : intervals) {
            // totally before the newInterval, append to output
            if (interval[1] < start) {
                output.add(interval);
                continue;
            }
            // totoally after the mergedInterval, maybe insert mergedInterval, then itself.
            if (end < interval[0]) {
                if (!inserted) {
                    output.add(new int[]{start, end});
                    inserted = true;
                }
                output.add(interval);
                continue;
            }
            // merge 2 intervals.
            start = Math.min(start, interval[0]);
            end = Math.max(end, interval[1]);
        }
        if (!inserted) {
            output.add(new int[]{start, end});
        }
        return output.toArray(new int[output.size()][]);
    }
}
</code>
</pre>