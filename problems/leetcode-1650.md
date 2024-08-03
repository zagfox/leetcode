---
date:   2024-08-03
---

# Leetcode 1650. Lowest Common Ancestor of a Binary Tree III

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."

## Same as LC 236
This problem provides additional link to parent. Even not using this, the problem can be resolved.

## Node back to root
Check the depth of two nodes, set the depth to be the same.
Then traverse back to root, when p and q hit, that's the LCA.

## Java Code
<pre>
<code>


</code>
</pre>
