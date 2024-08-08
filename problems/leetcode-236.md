---
date:   2024-07-18
---

# Leetcode 236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

## DFS
DFS traverse the binary tree, dfs returns the number of points(0, 1, 2) found. LCA is the node that two points are found separately at iself, or its left, or its right.

The implementation use clear return value, the # of nodes found. And use global variable to record LCA.
There are other ways to define the return parameter, the following works, but require some thinking
https://www.cnblogs.com/grandyang/p/4641968.html

## DFS Java Code
<pre>
<code>
class Solution {
    private TreeNode lcaNode = null;
    // Return the number of targets node (p or q) found.
    public int dfs(TreeNode node, TreeNode p, TreeNode q) {
        if (node == null) {
            return 0;
        }
        int selfCnt = 0;
        if (node == p || node == q) {
            selfCnt = 1;
        }
        int leftCnt = dfs(node.left, p, q);
        if (leftCnt == 2) {
            return 2;
        }
        int rightCnt = dfs(node.right, p, q);
        if (rightCnt == 2) {
            return 2;
        }
        int totalCnt = selfCnt + leftCnt + rightCnt;
        if (totalCnt == 2) {
            lcaNode = node;
        }
        return totalCnt;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root, p, q);
        return lcaNode;
    }
}
</code>
</pre>
