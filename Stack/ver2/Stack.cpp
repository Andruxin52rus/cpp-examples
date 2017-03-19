#include "Stack.h"
#include <cassert>

Stack::Stack() : head(0), peak(0) { }

Stack::~Stack() {
	node* current = head;
	node* next = 0;
	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

long long Stack::push(void* data) {
	node* current = new node;
	current->data = data;
	current->next = head;
	head = current;
	return peak++;
}

void* Stack::pop(long long index) {
	assert(0 <= index && index < peak);
	node* current = head;
	node* prev = 0;
	for (int i = peak - index - 1; i > 0; i--) {
		assert(current != 0);
		prev = current;
		current = current->next;
	}
	void* data = current->data;
	node* next = current->next;
	delete current;
	if (prev) prev->next = next;
	else head = next;
	peak--;
	return data;
}

void* Stack::pop() {
	return pop(peak - 1);
}

long long Stack::count() {
	return peak;
}