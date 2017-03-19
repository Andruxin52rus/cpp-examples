#pragma once
struct Stack
{
	long count;
	struct Link
	{
		void* data;
		Link* next;
		void initialize(void* data, Link* next);
	}* head;
	void initialize();
	void push(void* data);
	void* pop();
	void cleanup();
};