---
date:   2024-07-24
---

# Leetcode 199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

## BFS
Breath first search to list all nodes in one layer. And add the last element to the output.

## Java Code
<pre>
<code>
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> output = new LinkedList<>();
        if (root == null) {
            return output;
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            output.add(queue.peekLast().val);
            LinkedList<TreeNode> newQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    newQueue.add(node.left);
                }
                if (node.right != null) {
                    newQueue.add(node.right);
                }
            }
            queue = newQueue;
        }
        return output;
    }
}
</code>
</pre>
