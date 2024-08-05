---
date:   2024-06-18
---

# Leetcode 133. Clone Graph

Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.

Constraints:
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

## DFS
Depth-frist method also works here. Just need to keep track of the visited node. When visiting a node

1. Check if it is visited
2. If not, create a node for itself
3. Visit all its edges and add the link to itself
4. Return itself node.


## DFS Java Code
<pre>
<code>
class Solution {
    public Node dfsClone(Node node, HashMap<Integer, Node> clonedNodes) {
        Node clonedNode = clonedNodes.get(node.val);
        if (clonedNode != null) {
            return clonedNode;
        }
        
        clonedNode = new Node(node.val);
        clonedNodes.put(node.val, clonedNode);
        for (Node neighbor : node.neighbors) {
            clonedNode.neighbors.add(dfsClone(neighbor, clonedNodes));
        }
        return clonedNode;
    }
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        // Each node has unique val
        HashMap<Integer, Node> clonedNodes = new HashMap<>();
        return dfsClone(node, clonedNodes);
    }
}
</code>
</pre>

## BFS
Start from one node, keep track of all the nodes it can connect. When visititing one node

1. Check if it is visited
2. If not, create a node for itself
3. Visit its edges, if edge is visited, directly add. If not, create an edge (but do not mark as visited), push the edge to handling queue

## DFS Java Code
<pre>
<code>
class Solution {
    public Node cloneGraph(Node root) {
        if (root == null) {
            return null;
        }
        // Each node's value is unique.
        HashMap<Integer, Node> clonedNodes = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            Node clonedNode = clonedNodes.get(node.val);
            if (clonedNode == null) {
                // should only happen for first node
                clonedNode = new Node(node.val);
                clonedNodes.put(node.val, clonedNode);
            }
            for (Node neighbor : node.neighbors) {
                Node clonedNeighbor = clonedNodes.get(neighbor.val);
                if (clonedNeighbor == null) {
                    clonedNeighbor = new Node(neighbor.val);
                    clonedNodes.put(neighbor.val, clonedNeighbor);
                    // visited check happens here.
                    queue.add(neighbor);
                }
                clonedNode.neighbors.add(clonedNeighbor);
            }
        }
        return clonedNodes.get(1);
    }
}
</code>
</pre>