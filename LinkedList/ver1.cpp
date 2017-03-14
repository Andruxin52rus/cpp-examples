#include <iostream>
using namespace std;

struct node
{
	int index;
	node* next;
};

void makeLinkedList(node* first, int length) {
	node* nodes = new node[length - 1];
	first->index = 0;
	first->next = &nodes[0];
	for (int i = 0; i < length - 1; i++) {
		nodes[i].index = i + 1;
		if (i < length - 2) nodes[i].next = &nodes[i + 1];
		else nodes[i].next = NULL;
	}
}

void printLinkedList(node* first) {
	node* current = first;
	while (current != NULL) {
		cout << "Current node has index " << current->index << " and "
		"points to " << long(current->next) << endl;
		current = current->next;
	}
}

void clearLinkedList(node* first) {
	delete[] first->next;
}

int main() {
	node n;
	makeLinkedList(&n, 20);
	printLinkedList(&n);
	clearLinkedList(&n);
}
