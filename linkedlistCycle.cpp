/* Linked List Cycle */
class Solution {
public:
	bool hasCycle(ListNode *head) {
		// Tricky algorithm, use "the Tortoise and the Hare" algorithm
		// It is also named Floyd's cycle finding algorithm
		if (head == NULL)
			return false;
		ListNode *p = head, *q = head;
		while (true) {
			if (p->next != NULL && p->next->next != NULL)
				p = p->next->next;
			else
				return false;
			if (q->next != NULL)
				q = q->next;
			else
				return false;
			if (p == q)
				return true;
		}
	}
};
/* Linked List Cycle 2 */
class Solution2 {
public:
	ListNode * hasCycle(ListNode *head) {
		// First find whether there is loop
		if (head == NULL)
			return NULL;
		ListNode *p = head, *q = head, *pt;
		while (true) {
			if (p->next != NULL && p->next->next != NULL)
				p = p->next->next;
			else
				return NULL;
			if (q->next != NULL)
				q = q->next;
			else
				return NULL;
			if (p == q)
				break;
		}
		// Searching from head, ac in 132ms
		pt = head;
		while (true) {
			while (true) {
				if (q == pt)
					return pt;
				q = q->next;
				if (q == p)
					break;
			}
			pt = pt->next;
		}

	}
};
/* 
 * Linked List Cycle 2
 * Ref: http://umairsaeed.com/2011/06/23/finding-the-start-of-a-loop-in-a-circular-linked-list/
 * 		http://www.cnblogs.com/hiddenfox/p/3408931.html
 */
class Solution3 {
public:
	ListNode * hasCycle(ListNode *head) {
		// First find whether there is loop
		if (head == NULL)
			return NULL;
		ListNode *p = head, *q = head, *pt;
		while (true) {
			if (p->next != NULL && p->next->next != NULL)
				p = p->next->next;
			else
				return NULL;
			if (q->next != NULL)
				q = q->next;
			else
				return NULL;
			if (p == q)
				break;
		}
		// Tricky here, just need to go same step to meet
		// Meet point is the start point of loop
		// AC in 72ms
		p = head;
		while (p != q) {
			p = p->next;
			q = q->next;
		}
		return p;
	}
};
