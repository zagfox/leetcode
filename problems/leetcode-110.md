---
date:   2024-06-24
---

# Leetcode 110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

## Full search solution
BFS can be used for searching, but the number of leaf node in one layer might be very large. This method may use too much memory.

DFS algorithm, the return value is whether the tree is balanced. In addition, it also needs to keep track of the depth observed during left/right side traversal. If left / right side depth gap
is too large, mark this node as not balanced. And remember to update this node's depth before return.

## Java Code
<pre>
<code>
class Solution {
    class State {
        public int depth;
        State() {
            this.depth = 0;
        }
        State(int depth) {
            this.depth = depth;
        }
        State(State state) {
            this.depth = state.depth;
        }
    }
    // State keeps the max depth below this node observed during DFS.
    // If left side or right side is not balanced, return false.
    // If left side depth and right side depth gap is too large, return false.
    // Mark this node's depth as the max of left / right depth + 1.
    public boolean dfs(TreeNode node, State state) {
        if (node == null) {
            return true;
        }

        State leftState = new State(0);
        if (!dfs(node.left, leftState)) {
            return false;
        }
        State rightState = new State(0);
        if (!dfs(node.right, rightState)) {
            return false;
        }
        if (Math.abs(leftState.depth - rightState.depth) > 1) {
            return false;
        }
        state.depth = Math.max(leftState.depth, rightState.depth) + 1;
        return true;
    }
    public boolean isBalanced(TreeNode root) {
        return dfs(root, new State());
    }
}
</code>
</pre>

## Slight modification
The dfs return value is boolean, the other way is to define the dfs to return the depth of the node. And use a global var to record whether the tree is balanced.