---
date:   2024-06-18
---

# Leetcode 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

## Quick Slow Pointer
Two pointers, the slow pointer move 1 node at a time, and the quick pointer move 2 nodes at a time. When the quick pointer reach the end, the slow pointer is at the middle.

## Java Code
<pre>
<code>
class Solution {
    public ListNode middleNode(ListNode head) {
        if (head == null) return null;
        ListNode quick = head, slow = head;
        while (quick != null && quick.next != null) {
            quick = quick.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
</code>
</pre>