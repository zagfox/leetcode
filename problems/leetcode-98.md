---
date:   2024-07-12
categories: dynamic_programing
---

# Leetcode 98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

## DFS
Traverse each node, and each node have a requirement to be in a range [min, max] determined
by its ancesters.

## DFS Java Code
<pre>
<code>
class Solution {
    public boolean traverse(TreeNode node, Integer min, Integer max) {
        if (node == null) {
            return true;
        }
        if (min != null && node.val <= min) {
            return false;
        }
        if (max != null && node.val >= max) {
            return false;
        }
        if (!traverse(node.left, min, node.val)) {
            return false;
        }
        if (!traverse(node.right, node.val, max)) {
            return false;
        }
        return true;
    }
    public boolean isValidBST(TreeNode root) {
        return traverse(root, null, null);
    }
}
</code>
</pre>
