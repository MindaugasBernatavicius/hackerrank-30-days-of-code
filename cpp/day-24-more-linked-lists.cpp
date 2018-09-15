#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int d) {
			data = d;
			next = NULL;
		}
};

class Solution {
	public:
		Node *removeDuplicates(Node *head) {
			Node *trackerHead = head;
			Node *tmp;
			while (trackerHead != NULL && trackerHead->next != NULL) {
				if (trackerHead->data == trackerHead->next->data) {
					tmp = trackerHead->next->next;
					if (tmp == NULL)	// handle: ...->a->a->NULL
						delete trackerHead->next;
					trackerHead->next = NULL;
					// 1. ...b->a->a->a->NULL
					// 2.		...b->a->a->NULL
					// 3.			 ...b->a->NULL
					trackerHead->next = tmp;
				} else {
					trackerHead = trackerHead->next;
				}
			}
			return head;
		}

		Node *insert(Node *head, int data) {
			Node *p = new Node(data);
			if (head == NULL) {
				head = p;
			} else if (head->next == NULL) {
				head->next = p;
			} else {
				Node *start = head;
				while (start->next != NULL) {
					start = start->next;
				}
				start->next = p;
			}
			return head;
		}
		
		void display(Node *head) {
			Node *start = head;
			while (start) {
				cout << start->data << " ";
				start = start->next;
			}
		}
};

int main() {
	Node *head = NULL;
	Solution mylist;
	int T, data;
	cin >> T;
	while (T-- > 0) {
		cin >> data;
		head = mylist.insert(head, data);
	}
	head = mylist.removeDuplicates(head);
	mylist.display(head);
}
