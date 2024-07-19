---
date:   2024-07-18
---

# Leetcode 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Array merge

Sort the input intervals by start. Then for each interval, check if it can merge with next intervals. If unable to merge, then insert it into the result.

## Java Code
<pre>
<code>
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return null;
        }
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        LinkedList<int[]> outputs = new LinkedList<>();
        int[] output = null;
        for (int[] interval : intervals) {
            if (output == null) {
                output = new int[]{interval[0], interval[1]};
                continue;
            }
            // Overlap, merge them.
            if (interval[0] <= output[1]) {
                output[1] = Math.max(output[1], interval[1]);
                continue;
            }
            outputs.add(new int[]{output[0], output[1]});
            output[0] = interval[0];
            output[1] = interval[1];
        }
        if (output != null) {
            outputs.add(new int[]{output[0], output[1]});
        }
        return outputs.toArray(new int[outputs.size()][]);
    }
}
</code>
</pre>
