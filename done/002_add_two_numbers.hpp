#ifndef SOLUTION
#define SOLUTION

#include "util.h"
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	
	ListNode *p1=l1, *p2=l2, *p11=NULL;
	while (p1 && p2) {
		p1->val += p2->val;
		if (p1->val >= 10) {
			p1->val -= 10;
			if (p1->next) {
				p1->next->val += 1;
			}
			else {
				p1->next = new ListNode(1);
			}
		}
		p11 = p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1) {
		for (; p1; p1 = p1->next) {
			if (p1->val >= 10) {
				p1->val -= 10;
				if (p1->next) {
					p1->next->val += 1;
				}
				else {
					p1->next = new ListNode(1);
					return l1;
				}
			}
			else {
				return l1;
			}
		}
	}
	else if (p2) {
		p11->next = p2;
	}
	
	return l1;
}

void test() {
	test({8}, {9});
	test({8}, {9,8});
	test({2,4,5}, {5,6,5});
	test({1}, {9,9,9});
}

void test(vector<int> v1, vector<int> v2) {
	ListNode* l1 = createList(v1);
	ListNode* l2 = createList(v2);
	printList(l1);
	cout << " + ";
	printList(l2);
	cout << " = ";
	l1 = addTwoNumbers(l1, l2);
	printList(l1);
	cout << endl;
}

ListNode* createList(vector<int>& v) {
	if (v.size() < 1) {
		return NULL;
	}
	ListNode *h = new ListNode(v[0]), *p=h;
	for (int i = 1; i < v.size(); ++i) {
		p->next = new ListNode(v[i]);
		p = p->next;
	}
	return h;
}

void printList(ListNode* h) {
	while (h) {
		cout << h->val;
		h = h->next;
	}
}

};

#endif