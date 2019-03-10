#pragma once

class Stack
{
public:
	Stack();
	Stack(void** data_pointers, long long length);
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
