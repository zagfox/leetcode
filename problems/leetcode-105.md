---
date:   2024-07-25
---

# Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

## Recursion
First find root, which is first element of preorder traversal. Then find root in the inorder sequence, left side of it are root's left nodes, right side of it are root's right nodes.

## Java Code
<pre>
<code>
class Solution {
    private int preorderPos = 0;
    // Build binary tree, use inorder in the range [start, limit)
    public TreeNode build(int[] preorder, int[] inorder, int inorderStart, int inorderLimit) {
        if (preorderPos == preorder.length) {
            return null;
        }
        if (inorderStart >= inorderLimit) {
            return null;
        }
        TreeNode node = new TreeNode(preorder[preorderPos]);
        ++preorderPos;
        // Find node.val's position in the inorder sequence
        int pos = -1;
        for (pos = inorderStart; pos < inorderLimit; ++pos) {
            if (inorder[pos] == node.val) {
                break;
            }
        }
        node.left = build(preorder, inorder, inorderStart, pos);
        node.right = build(preorder, inorder, pos+1, inorderLimit);
        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length);
    }
}
</code>
</pre>
