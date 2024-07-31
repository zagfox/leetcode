---
date:   2024-07-31
---

# Leetcode 1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

## DFS
Traverse the binary tree
1. If the current node is to be deleted, remove itself from final set, add its left and right node to the final set.
2. If current node's left is to be deleted, set its left to null, goes to its left
3. If current node's right is to be deleted, set its right to null, goes to its right

## Java Code
<pre>
<code>
class Solution {
    public HashMap<Integer, TreeNode> output;
    public void traverse(TreeNode node, HashSet<Integer> toDelete) {
        if (node == null) {
            return;
        }
        if (toDelete.contains(node.val)) {
            output.remove(node.val);
            if (node.left != null) {
                output.put(node.left.val, node.left);
                traverse(node.left, toDelete);
            }
            if (node.right != null) {
                output.put(node.right.val, node.right);
                traverse(node.right, toDelete);
            }
            return;
        }
        // Cases for its left or right are to be deleted
        if (node.left != null) {
            traverse(node.left, toDelete);
            if (toDelete.contains(node.left.val)) {
                node.left = null;
            }
        }
        if (node.right != null) {
            traverse(node.right, toDelete);
            if (toDelete.contains(node.right.val)) {
                node.right = null;
            }
        }
        return;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        output = new HashMap<>();
        HashSet<Integer> toDelete = new HashSet<>();
        for (int val : to_delete) {
            toDelete.add(val);
        }
        if (root != null) {
            output.put(root.val, root);
        }
        traverse(root, toDelete);
        List<TreeNode> list = new LinkedList<>();
        for (TreeNode node : output.values()) {
            list.add(node);
        }
        return list;
    }
}
</code>
</pre>
