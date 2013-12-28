#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodePair {
	ListNode *head;
	ListNode *tail;
	ListNodePair(ListNode *p, ListNode *q) : 
		head(p), tail(q) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		// Time limit exceeded
		ListNode *p, *pl, *q, *ql;
		for (p = head; p != NULL && p->next != NULL && p->next->next != NULL;) {
			q = p;
			while (q->next->next != NULL)
				q = q->next;
			ql = q->next;
			q->next = NULL;

			pl = p->next;
			ql->next = pl;
			p->next = ql;
			p = pl;
		}
	}
};

class Solution2 {
public:
	ListNode *recurList(ListNode *head, int len) {
		// Has huge problem to assign null to value
		if (len <= 2)
			return head;
		ListNode *p = recurList(head->next, len-2);
		ListNode *q = head;
		int i;
		for (i = 0; i < len-1; i++)
			q = q->next;
		head->next = q;
		q->next = p;
		if (len-2 == 1)
			p->next = NULL;	// Has huge problem to assign null to this value,
							// Can't get to value behind it in upper recursion
		if (len-2 == 2)
			p->next->next = NULL;
		return head;
	}
	void reorderList(ListNode *head) {
		int len;
		ListNode *p;
		for (p = head, len = 0; p != NULL; p = p->next, len++);
		head = recurList(head, len);
	}
};

class Solution3 {
public:
	ListNodePair recurList(ListNode *head, int len) {
		// Use recursion, return the current head and tail in last recursion
		// The idea is divide and conquer to reduce the time need to find next tail
		if (len <= 2) {
			ListNode *tail = head;
			while (len--)	// A tricky place
				tail = tail->next;
			return ListNodePair(head, tail);
		}
		ListNodePair pair = recurList(head->next, len-2);
		
		// The returned tail should be the next of previous tail
		ListNodePair retPair(head, pair.tail->next);
		head->next = pair.tail;
		pair.tail->next = pair.head;
		return retPair;
	}
	void reorderList(ListNode *head) {
		// AC in 328ms
		// I like this code better than Solution4, although use a struct, return two pointers
		// The structures and function definition is very clear and clean
		if (head == NULL)
			return;
		int len;
		ListNode *p;
		for (p = head, len = 0; p != NULL; p = p->next, len++);
		recurList(head, len);
		for (p = head; len > 1; p = p->next, len--);
		p->next = NULL;
	}
};

class Solution4 {
public:
	ListNode  *recurList(ListNode *head, int len) {
		// Use recursion
		// Return tail corresponding to the head in last recursion
		if (len <= 2) {
			ListNode *tail = head;
			while (len--)	// Little tricky
				tail = tail->next;
			return tail;
		}
		ListNode *tail = recurList(head->next, len-2);
		
		// The returned tail should be the next of previous tail
		ListNode *retTail = tail->next;
		ListNode *tmp = head->next;
		// Link the head and tail
		head->next = tail;
		tail->next = tmp;
		return retTail;
	}
	void reorderList(ListNode *head) {
		// AC in 320ms
		if (head == NULL)
			return;
		int len;
		ListNode *p;
		for (p = head, len = 0; p != NULL; p = p->next, len++);
		recurList(head, len);
		for (p = head; len > 1; p = p->next, len--);
		p->next = NULL;
	}
};

// Solution5
// divide the list into two parts, and merge them together
int main() {
	Solution4 sln;
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	a->next = b;
	b->next = c;
	sln.reorderList(a);
	cout << a->val << a->next->val << a->next->next->val << endl;
	return 0;
}
