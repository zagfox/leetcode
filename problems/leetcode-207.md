---
date:   2024-06-18
---

# Leetcode 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

## Topology Sort
For each class, have a set to tell its untaken prerequisites. For each round, take one class that has 0 prerequisites. Once that's done, remove it from its children class's prerequisites.

## Java Code
<pre>
<code>
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // For each class, what are its unfinished prerequisites.
        HashMap<Integer, HashSet<Integer>> dependenciesMap = new HashMap<>();
        for (int[] prerequisite : prerequisites) {
            // a -> b
            int b = prerequisite[0];
            int a = prerequisite[1];
            if (!dependenciesMap.containsKey(b)) {
                dependenciesMap.put(b, new HashSet<Integer>());
            }
            Set<Integer> dependencies = dependenciesMap.get(b);
            dependencies.add(a);
        }

        HashSet<Integer> unfinished = new HashSet<>();
        for (int i = 0; i < numCourses; ++i) {
            unfinished.add(i);
        }
        while (!unfinished.isEmpty()) {
            // take a class with no dependency
            int id = -1;
            for (int i : unfinished) {
                if (!dependenciesMap.containsKey(i) || dependenciesMap.get(i).isEmpty()) {
                    id = i;
                    break;
                }
            }
            if (id == -1) {
                break;
            }
            // Remove it from unfinished, and update unfinished dependencies
            unfinished.remove(id);
            for (HashSet<Integer> dependencies : dependenciesMap.values()) {
                dependencies.remove(id);
            }
        }
    
        return unfinished.isEmpty();
    }
}
</code>
</pre>

## Topology Sort II
In the implementation, I use dependenciesMap, to store a class's dependencies list. The other way to implement, is to store it as a graph, that one class can enable XXX classes. This approach needs to introduce another node incoming edges counts. To tell that for each node, it has X incoming edges.

Fundamentally, this way to represent graph is from src->dest, which is more natural. But it needs additional helper to know each node's incoming count.

## Java Code
<pre>
<code>
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        HashMap<Integer, HashSet<Integer>> outEdges = new HashMap<>();
        HashMap<Integer, Integer> inEdgesCount = new HashMap<>();
        for (int i = 0; i < numCourses; ++i) {
            outEdges.put(i, new HashSet<Integer>());
            inEdgesCount.put(i, 0);
        } 
        for (int[] prerequisite : prerequisites) {
            // a->b
            int b = prerequisite[0];
            int a = prerequisite[1];
            outEdges.get(a).add(b);
            inEdgesCount.put(b, inEdgesCount.get(b) + 1);
        }
        // Begin iterating
        HashSet<Integer> unfinished = new HashSet<>();
        for (int i = 0; i < numCourses; ++i) {
            unfinished.add(i);
        }
        while (!unfinished.isEmpty()) {
            int id = -1;
            for (int i : unfinished) {
                if (inEdgesCount.get(i) == 0) {
                    id = i;
                    break;
                }
            }
            if (id == -1) {
                break;
            }
            unfinished.remove(id);
            for (int i : outEdges.get(id)) {
                inEdgesCount.put(i, inEdgesCount.get(i) - 1);
            }
        }

        return unfinished.isEmpty();
    }
}
</code>
</pre>

<h2> DFS </h2>
Another idea is to traverse the DAG graph with DFS. If there is cyclic, DFS will hit the same node twice. Each node has a state, 0 is unvisited, -1 is being visit, and 1 is finished vist.

<h2> Java Code </h2>
<pre>
<code>
class Solution {
    private HashMap<Integer, HashSet<Integer>> outEdges;
    int[] visitState;

    // return true if can visit without cyclic, false if there is syclic.
    public boolean dfs(int node) {
        if (visitState[node] == 1) return true;
        if (visitState[node] == -1) return false;

        visitState[node] = -1;
        for (int i : outEdges.get(node)) {
            if (!dfs(i)) {
                return false;
            }
        }
        visitState[node] = 1;
        return true;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        outEdges = new HashMap<>();
        for (int i = 0; i < numCourses; ++i) {
            outEdges.put(i, new HashSet<Integer>());
        } 
        for (int[] prerequisite : prerequisites) {
            // a->b
            int b = prerequisite[0];
            int a = prerequisite[1];
            outEdges.get(a).add(b);
        }
        visitState = new int[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
}
</code>
</pre>