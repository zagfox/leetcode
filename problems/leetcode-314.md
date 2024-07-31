---
date:   2024-07-31
---

# Leetcode 314. Binary Tree Vertical Order Traversal

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

## Traverse and record
Use a TreeMap<col_id, list> to store the list of this column. 

For DFS, it use pre-order to traverse, it needs to record both the row and col for the correct sorting. Like map {col}{row} -> vals. Then output per column.

For BFS, it stores column id together with the node.

## BFS Java Code
<pre>
<code>
class Solution {
    public class Entry {
        TreeNode node;
        int col;
        Entry(TreeNode node, int col) {
            this.node = node;
            this.col = col;
        }
    }
    
    public List<List<Integer>> verticalOrder(TreeNode root) {
        TreeMap<Integer, List<Integer>> colToNodes = new TreeMap<>();
        LinkedList<Entry> queue = new LinkedList<>();
        queue.add(new Entry(root, 0));
        while (!queue.isEmpty()) {
            Entry entry = queue.removeFirst();
            if (entry.node == null) {
                continue;
            }
            int col = entry.col;
            if (!colToNodes.containsKey(col)) {
                colToNodes.put(col, new LinkedList<Integer>());
            }
            colToNodes.get(col).add(entry.node.val);
            queue.add(new Entry(entry.node.left, col-1));
            queue.add(new Entry(entry.node.right, col+1));
        }
        List<List<Integer>> outputs = new LinkedList<>();
        colToNodes.forEach((col, nodes) -> {
            outputs.add(nodes);
        });
        return outputs;
    }
}
</code>
</pre>
