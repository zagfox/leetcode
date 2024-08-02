---
date:   2024-06-16
---

# Leetcode 206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

## Bubble Move
Create a preHead node before the original head. Each time, move one node from position(i) to the place between preHead and Head.

## Java Code
<pre>
<code>
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode preHead = new ListNode(0, head);
        // orignal head will be moved to back over and over. preCurr
        // always point to the original head.
        ListNode preCurr = head;
        ListNode curr = head.next;
        while (curr != null) {
            preCurr.next = curr.next;
            curr.next = preHead.next;
            preHead.next = curr;
            // Prepare for next round
            curr = preCurr.next;
        }
        return preHead.next;
    }
}
</code>
</pre>
