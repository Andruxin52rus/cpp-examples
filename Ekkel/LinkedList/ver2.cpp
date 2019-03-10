#include <iostream>
using namespace std;

struct linked_list
{
	struct node
	{
		int index;
		node* next;
	}* nodes;

	void create(int length) {
		try {
			clear();
		} catch(const Exception) { }
		nodes = new node[length];
		for (int i = 0; i < length ; i++) {
			nodes[i].index = i;
			if (i < length - 1) nodes[i].next = &nodes[i + 1];
			else nodes[i].next = NULL;
		}
	}

	void print() {
		node* current = &nodes[0];
		if (current->index != 0) current = NULL;			
		while (current != NULL) {
			cout << "Current node has index " << current->index << " and "
			"points to " << long(current->next) << endl;
			current = current->next;
		}
	}

	void clear() {
		try {
			delete[] nodes;
		} catch(const Exception) { }
	}
};


int main() {
	linked_list l;
	// some crazy stuff here
	l.create(100);
	l.create(10);
	l.print();
	l.clear();
	l.clear();
	l.print();
}
