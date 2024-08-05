---
date:   2024-06-18
---

# Leetcode 141: Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

## Hash Map
The brute force solution is to iterate on the linked list. And use a HashMap to store all the visited node. This works but requires to store a lot of data in memory.
Space Complexity: O(N)

## Quick Slow Pointer
This is a special algorithm. Having two iterators on the linked list, one moves 2 nodes in one step, the other moves 1 node. After each step, the distance of quick/slow increase by 1. But it won't increase infinitely. If there is a loop of length M, the distance of quick/slow pointer is at most M-1. And if there is no loop, the iterator will hit the end of the linked list.

## Java Code
<pre>
<code>
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode quick = head, slow = head;
        while (quick != null && slow != null) {
            if (quick.next == null) {
                break;
            }
            quick = quick.next.next;
            slow = slow.next;
            if (quick == slow) {
                return true;
            }
        }
        return false;
    }
}
</code>
</pre>