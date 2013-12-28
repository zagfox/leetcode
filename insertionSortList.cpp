class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		// Init, add a prehead
		ListNode *p, *q, *prehead, *tail;
		prehead = new ListNode(-9999);
		prehead->next = head;
		tail = prehead;
		
		// Insertion sort
		while (tail->next != NULL) {
			p = tail->next;
			tail->next = p->next;
			q = prehead;
			while (q != tail && p->val > q->next->val)
				q = q->next;
			p->next = q->next;
			q->next = p;
			if (q == tail)
				tail = p;
		}
		head = prehead->next;
		delete(prehead);
		return head;
	}
};
