#pragma once

class Stack
{
public:
	Stack();
	~Stack();
	long long push(void* data);
	void* pop(long long index);
	void* pop();
	long long count();
private:
	long long peak;
	struct node
	{
		void* data;
		node* next;
	}* head;
};
