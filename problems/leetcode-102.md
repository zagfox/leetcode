---
date:   2024-06-22
---

# Leetcode 102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

<h2>BFS</h2>
Breath first search, using a queue with multiple iterations, and each iteration handles one layer.

<h2> Java Code </h2>
<pre>
<code>
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new LinkedList<List<Integer>>();
        }
        List<List<Integer>> outputs = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Queue<TreeNode> newQueue = new LinkedList<>();
            List<Integer> output = new LinkedList<>();
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                output.add(node.val);
                if (node.left != null) {
                    newQueue.add(node.left);
                }
                if (node.right != null) {
                    newQueue.add(node.right);
                }
            }
            outputs.add(output);
            queue = newQueue;
        }
        return outputs;
    }
}
</code>
</pre>
