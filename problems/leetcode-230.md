---
date:   2024-07-29
---

# Leetcode 230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

## In-order traversal
It is a binary search tree, left subtree is always smaller than node, right subtree is always larger than node. The In-order traversal can access the values in increasing order.

## Java Code
<pre>
<code>
class Solution {
    int K;
    public class State {
        public int seq;
        public int val;
        State(int seq, int val) {
            this.seq = seq;
            this.val = val;
        }

    }
    public void inorderTraverse(TreeNode node, State state) {
        if (node == null) {
            return;
        }
        inorderTraverse(node.left, state);
        if (state.seq >= K) {
            return;
        }
        ++state.seq;
        state.val = node.val;
        if (state.seq >= K) {
            return;
        }
        inorderTraverse(node.right, state);
    }
    public int kthSmallest(TreeNode root, int k) {
        K = k;
        State state = new State(0, 0);
        inorderTraverse(root, state);
        return state.val;

    }
}
</code>
</pre>
