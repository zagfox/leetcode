---
date:   2024-08-11
---

# Leetcode 210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

## Topology sort
Similar to Lc207, but Lc207 only requires to return whether can finish all course. And this asks to return course schedule.

To represent the graph, I use outEdges. To easily find next course to take, I keep a helper data structure inEdgeCount.

## Java Code
<pre>
<code>
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, List<Integer>> outEdges = new HashMap<>();
        HashMap<Integer, Integer> inEdgeCount = new HashMap<>();
        for (int i = 0; i < numCourses; ++i) {
            outEdges.put(i, new LinkedList<Integer>());
            inEdgeCount.put(i, 0);
        }
        for (int[] prerequisite : prerequisites) {
            int src = prerequisite[1], dst = prerequisite[0];
            outEdges.get(src).add(dst);
            inEdgeCount.put(dst, inEdgeCount.getOrDefault(dst, 0) + 1);
        }
        
        HashSet<Integer> toFinish = new HashSet<>();
        for (int i = 0; i < numCourses; ++i) {
            toFinish.add(i);
        }
        int iteration = 0;
        int[] schedule = new int[numCourses];
        while(!toFinish.isEmpty()) {
            int candidate = -1;
            for (int i : toFinish) {
                if (inEdgeCount.get(i) == 0) {
                    candidate = i;
                    break;
                }
            }
            if (candidate == -1) {
                break;
            }
            for (int out : outEdges.get(candidate)) {
                inEdgeCount.put(out, inEdgeCount.get(out)-1);
            }
            toFinish.remove(candidate);
            schedule[iteration] = candidate;
            ++iteration;
        }
        if (!toFinish.isEmpty()) {
            return new int[]{};
        }
        return schedule;
    }
}
</code>
</pre>
