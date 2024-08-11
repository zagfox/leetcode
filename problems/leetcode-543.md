---
date:   2024-06-18
---

# Leetcode 543: Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

## Recursion
Traverse the whole tree. For each node, find its left node's depth to leaf, and its right node's depth to leaf. Using a global variable to record tree's diameter.

## Java Code
<pre>
<code>
class Solution {
    private int diameter = 0;
    // Visit all tree node, return value is the max length from this node to leaf.
    public int visit(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int lLength = visit(node.left);
        int rLength = visit(node.right);
        if (lLength + rLength > diameter) {
            diameter = lLength + rLength;
        }
        return 1 + Math.max(lLength, rLength);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        visit(root);
        return diameter;
    }
}
</code>
</pre>