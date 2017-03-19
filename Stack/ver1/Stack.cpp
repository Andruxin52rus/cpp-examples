#include "Stack.h"

void Stack::initialize() { 
	head = 0;
	count = 0;
}

void Stack::push(void* data) {
	Link* new_link = new Link;
	new_link->initialize(data, head);
	head = new_link;
	count++;
}

void* Stack::pop() {
	if (count == 0) return 0;
	void* data = head->data;
	Link* old_head = head;
	head = head->next;
	delete old_head;
	count--;
	return data;
}

void Stack::cleanup() {
	while (count != 0)
	{
		Link* old_head = head;
		head = head->next;
		delete old_head;
		count--;
	}
}

void Stack::Link::initialize(void* data, Link* next) {
	this->data = data;
	this->next = next;
}