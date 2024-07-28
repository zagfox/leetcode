---
date:   2024-07-28
---

# Leetcode 310. Minimum Height Trees

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

## Calculate all distances
Maintain a matrix of the existing know min-distance from one node to others. When adding an edge a-b. Check b's distance to all neighbors, for one example c. Then a-c distance is the min of existing a-c distance, and 1+(bc distance).

The algorithm has a problem. That it only find neighbors one time. But in practice, it may require to find neighbors multiple times.

## Gradual Shrink
Use a graph to store direct connections between points. Define leaf nodes as the nodes that only have 1 direct peer. Conduct process multiple rounds, for each round, remove all leaf nodes. Until there is only one or two nodes.

## Java Code
<pre>
<code>
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<HashSet<Integer>> graph = new ArrayList<>(n);
        HashSet<Integer> roots = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new HashSet<Integer>());
            roots.add(i);
        }
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        while (roots.size() > 2) {
            List<Integer> leaves = new LinkedList<Integer>();
            for (int i = 0; i < n; ++i) {
                if (graph.get(i).size() == 1) {
                    leaves.add(i);
                }
            }
            for (int leaf : leaves) {
                int other = -1;
                for (int i : graph.get(leaf)) {
                    other = i;
                }
                graph.get(leaf).remove(other);
                graph.get(other).remove(leaf);
                roots.remove(leaf);
            }
        }
        List<Integer> output = new LinkedList<Integer>();
        for (int i : roots) {
            output.add(i);
        }
        return output;
    }
}
</code>
</pre>
