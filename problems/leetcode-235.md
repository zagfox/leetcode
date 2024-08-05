---
date:   2024-06-18
---

# Leetcode 235: Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

## Full search solution
This solution does full DFS in the tree. Depends on the left, right and self node value, return 
targets node. If the algorithm confirms answer is self node, return the node. If algorithm confirms the answer is on the left side or right side, ask left/right side to search for the answer node and return that.

For implementation, it will be easier for the dfs to return the number of nodes contains. And use a global var to record LCA.

<h2> Java Code </h2>
<pre>
<code>
class Solution {
    // If left match and right match, return self
    // If self match, and one of left/right match, return self
    // If only self match, return self
    // If only one of left / right match, return left/right matched.
    // If none match, return null
    public TreeNode dfs(TreeNode node, TreeNode p, TreeNode q) {
        if (node == null) {
            return null;
        }
        boolean selfMatched = false;
        if (node == p || node == q) {
            selfMatched = true;
        }
        TreeNode leftRet = dfs(node.left, p, q);
        TreeNode rightRet = dfs(node.right, p, q);
        
        if (selfMatched) {
            return node;
        }
        if (leftRet != null && rightRet != null) {
            return node;
        }
        if (leftRet != null && rightRet == null) {
            return leftRet;
        }
        if (leftRet == null && rightRet != null) {
            return rightRet;
        }
        return null;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return dfs(root, p, q);
    }
}
</code>
</pre>

## Smarter search solution
The full search solution didn't make use of the property of binary search tree. That works for any kind of tree. For binary search tree, the left child holding values are always smaller than current node value. And right child holding values are always larger than the current node value. The DFS algorithm can only choose at most one side of branch to further search.

## Java Code
<pre>
<code>
class Solution {
    // If self node match, then either the final answer is this node. Or return this node up
    // to find the right answer.
    // If p and q's value is smaller than node's value, answer must come from left. Rely on left
    // branch to find the answer.
    // Similarly for p and q is larger than node's value, rely on right branch.
    // If p and q are on two sides of the current value, then p and q should exist on the two children
    // of current, return current node.
    public TreeNode dfs(TreeNode node, TreeNode p, TreeNode q) {
        if (node == null) {
            return null;
        }
        if (node.val == p.val || node.val == q.val) {
            return node;
        }
        int small = Math.min(p.val, q.val);
        int large = Math.max(p.val, q.val);
        if (small < node.val && node.val < large) {
            return node;
        }
        if (large < node.val) {
            return dfs(node.left, p, q);
        }
        if (node.val < small) {
            return dfs(node.right, p, q);
        }
        return null;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return dfs(root, p, q);
    }
}
</code>
</pre>