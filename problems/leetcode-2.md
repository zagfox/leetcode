---
date:   2024-08-08
---

# Leetcode 2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## Big int add
Need to handle carry bit for 
  1. during the computation
  2. after both list are handled

## Java Code
<pre>
<code>
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode preHead = new ListNode();
        ListNode q = preHead;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int out = carry;
            if (l1 != null) {
                out += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                out += l2.val;
                l2 = l2.next;
            }
            if (out >= 10) {
                out = out - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            q.next = new ListNode(out);
            q = q.next;
        }
        if (carry == 1) {
            q.next = new ListNode(1);
            q = q.next;
        }
        return preHead.next;
    }
}
</code>
</pre>
