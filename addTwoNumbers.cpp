/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// Original version, can ac
		int val1, val2, val, carry;
		ListNode *p1 = l1, *p2 = l2;
		ListNode *head , *p, *q;
		if (p1 == NULL && p2 == NULL)
			return NULL;
		head = new ListNode(-1);
		p = head;
		carry = 0;
		while (p1 != NULL || p2 != NULL) {
			val1 = 0;
			if (p1 != NULL) {
				val1 = p1->val;
				p1 = p1->next;
			}
			val2 = 0;
			if (p2 != NULL) {
				val2 = p2->val;
				p2 = p2->next;
			}
			val = (val1 + val2 + carry)%10;
			carry = (val1 + val2 + carry)/10; 
			q = new ListNode(val);
			p->next = q;
			p = q;
		}
		if (carry != 0) {
			q = new ListNode(carry);
			p->next = q;
			p = q;
		}
		return head->next;	
	}
};

class Solution2 {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// Inspired by "fish in water", modify the code
		int val1, val2, val, carry;
		ListNode *p1 = l1, *p2 = l2;
		ListNode *head , *p;
		
		head = new ListNode(-1);
		p = head;
		carry = 0;
		while (p1 != NULL || p2 != NULL) {
			val1 = 0;
			if (p1 != NULL) {
				val1 = p1->val;
				p1 = p1->next;
			}
			val2 = 0;
			if (p2 != NULL) {
				val2 = p2->val;
				p2 = p2->next;
			}
			// Begin calculate
			val = (val1 + val2 + carry)%10;
			carry = (val1 + val2 + carry)/10; 
			p->next = new ListNode(val);
			p = p->next;
		}
		if (carry != 0) {
			p->next = new ListNode(carry);
			p = p->next;
		}
		p = head->next;
		delete(head); 	// Avoid memory leak
		return p;	
	}
}
