---
date:   2024-08-08
---

# Leetcode 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

## Priority Queue and merge sort
Use priority queue to keep the smallest number, and use merge sort to generate output list.

## Java Code
<pre>
<code>
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(new Comparator<ListNode>() {
            public int compare(ListNode a, ListNode b) {
                return Integer.compare(a.val, b.val);
            }
        });
        for (ListNode node : lists) {
            if (node != null) {
                minHeap.add(node);
            }
        }

        ListNode preHead = new ListNode();
        ListNode p = preHead;
        while (!minHeap.isEmpty()) {
            ListNode node = minHeap.poll();
            if (node == null) {
                continue;
            }
            p.next = node;
            p = p.next;
            if (node.next != null) {
                minHeap.add(node.next);
            }
        }
        return preHead.next;

    }
}
</code>
</pre>
