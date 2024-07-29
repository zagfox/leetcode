---
date:   2024-06-14
---

# Leetcode 226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.

# Recursion
There are unlimitted layers, this has to be resolved while recursion. Starting from the root, do the left and right swap. Then continuously doing the same for all its children.
Time complexity: O(N)

<h2> Java Code </h2>
<pre>
<code>
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode newLeft = invertTree(root.left);
        TreeNode newRight = invertTree(root.right);
        root.left = newRight;
        root.right = newLeft;
        return root;
    }
}
</code>
</pre>