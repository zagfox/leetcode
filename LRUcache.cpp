#include <iostream>
using namespace std;

class mEntry {
public:
	int key;
	int value;
	mEntry *next;
};

class LRUCache{
	// Use single side list, O(n) to get and set
private:
	int lstCap;
	int lstLen;
	mEntry *lstEntry;

public:
	LRUCache(int capacity) {
		lstCap = capacity;
		lstLen = 0;
		lstEntry = new mEntry();
	}

	// Check if it exist
	int exist(int key) {
		mEntry *p = lstEntry->next;
		while (p != NULL) {
			if (p->key == key)
				return p->value;
			p = p->next;
		}
		return -1;
	}
	
	// Find it
	int get(int key) {
		mEntry *p = lstEntry;
		while (p->next != NULL) {
			if (p->next->key == key)
				break;
			p = p->next;
		}
		// If not found
		if (p->next == NULL)
			return -1;
		// Find it, take it to the end of list
		mEntry *q = p->next;
		p->next = q->next;
		while (p->next != NULL)
			p = p->next;
		p->next = q;
		q->next = NULL;
		return q->value;
	}

	void replace(int key, int value) {
		mEntry *p = lstEntry->next;
		while (p != NULL) {
			if (p->key == key) {
				p->value = value;
				return;
			}
			p = p->next;
		}
	}

	void add(int key, int value) {
		mEntry *p = lstEntry;
		while(p->next != NULL)
			p = p->next;
		p->next = new mEntry();
		p = p->next;
		p->key = key;
		p->value = value;
	}

	void set(int key, int value) {
		// If exist
		if (exist(key) != -1) {
			replace(key, value);
			return;
		}
		// The element does not exist
		if (lstLen < lstCap) {
			add(key, value);
			lstLen++;
		}
		else {
			//Remove first element
			mEntry *p = lstEntry->next;
			lstEntry->next = p->next;
			delete p;
			add(key, value);
		}
	}
};

int main() {
	return 0;
}
