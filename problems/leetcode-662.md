---
date:   2024-08-08
---

# Leetcode 662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

## BFS with column info
Traverse the tree with BFS, and in the queue, record column information. Based on that, calculate a layer's max width.

Definition of width is unclear to me, cannot pass OJ.

## Java Code
<pre>
<code>
class Solution {
    class Entry {
        public TreeNode node;
        public int col;
        public Entry(TreeNode node, int col) {
            this.node = node;
            this.col = col;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        LinkedList<Entry> queue = new LinkedList<>();
        queue.add(new Entry(root, 0));
        int maxWidth = 0;
        while (!queue.isEmpty()) {
            Entry front = queue.getFirst();
            Entry last = queue.getLast();
            System.out.println("front col " + front.col + " last col " + last.col);
            if (last.col - front.col > maxWidth) {
                maxWidth = last.col - front.col;
            }
            LinkedList<Entry> newQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                Entry entry = queue.poll();
                if (entry.node.left != null) {
                    newQueue.add(new Entry(entry.node.left, entry.col - 1));
                }
                if (entry.node.right != null) {
                    newQueue.add(new Entry(entry.node.right, entry.col + 1));
                }
            }
            queue = newQueue;
        }
        return maxWidth;

    }
}
</code>
</pre>
