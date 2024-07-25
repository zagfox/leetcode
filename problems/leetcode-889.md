---
date:   2024-07-25
---

# Leetcode 889. Construct Binary Tree from Preorder and Postorder Traversal

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

## Recursion
preorder sequence:  [node][left][right]
postorder sequence: [left][right][node]

In each recusion, iterate preorder, create node, then find node's point in the post order sequence. Create the left side tree first. Then check how many nodes are used in the left, update the boundary and then create right side tree.

## Java Code
<pre>
<code>
class Solution {
    private int preorderPos = 0;
    public TreeNode build(int[] preorder, int[] postorder, int postStart, int postLimit) {
        if (preorderPos == preorder.length) {
            return null;
        }
        if (postStart >= postLimit) {
            return null;
        }
        TreeNode node = new TreeNode(preorder[preorderPos]);
        ++preorderPos;
        // Find node.val's position in postorder sequence
        int pos = -1;
        for (pos = postStart; pos < postLimit; ++pos) {
            if (postorder[pos] == node.val) {
                break;
            }
        }
        int preorderPosSnapshot = preorderPos;
        node.left = build(preorder, postorder, postStart, pos);
        int numLeft = preorderPos - preorderPosSnapshot;
        node.right = build(preorder, postorder, postStart+numLeft, pos);
        return node;
    }
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return build(preorder, postorder, 0, postorder.length);
    }
}
</code>
</pre>
