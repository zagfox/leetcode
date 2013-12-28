#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// Misunderstand the question of switching m and n
		if (m == n)
			return head;
		int i = 1;
		ListNode *p1, *p2, *p3, *q1, *q2, *q3;
		// Find m element and its prev and next
		q1 = head;
		q2 = head;
		q3 = q2->next;
		while (p2 ->next != NULL) {
			if (i == m)
				break;
			else {
				q1 = q2;
				q2 = q3;
				q3 = q3->next;
			}
			i++;
		}

		// Find n element and its prev and next
		p1 = q2;
		p2 = q2;
		p3 = q2->next;
		while (q2 ->next != NULL) {
			if (i == n)
				break;
			else {
				p1 = p2;
				p2 = p3;
				p3 = p3->next;
			}
			i++;
		}

		// Switch
		if (q2 == head)
			head = p2;
		else
			q1->next = p2;
		q2->next = p3;
		if (n - m > 1) {
			p2->next = q3;
			p1->next = q2;
		}
		else
			p2->next = q2;
		// Return head
		return head;
	}
};

/*
 * Beautiful code, as I may think
 * Use pre_head to ensure that p1 is in front of p2
 */
class Solution2 {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL)
			return head;
		int i;
		ListNode *pre_head, *p1, *p2, *p3, *q;
		// Add pre_head to ensure that p1 is always in front of p2
		pre_head = new ListNode(-1);
		pre_head->next = head;
		// Find position of p1
		p1 = pre_head;
		p2 = p1->next;
		for (i = 1; i < m; i++) {
			p1 = p2;
			p2 = p2->next;
		}
		// Begin reverse
		p3 = p2->next;
		for (; i < n; i++) {
			// Do rotate
			q = p1->next;
			p1->next = p3;
			p2->next = p3->next;
			p3->next = q;
			// p2, p3 are now reversed, swap it and add value
			swap(p2, p3);
			p2 = p3;
			p3 = p3->next;

		}
		return pre_head->next;
	}
};

int main() {
	return 0;
}

