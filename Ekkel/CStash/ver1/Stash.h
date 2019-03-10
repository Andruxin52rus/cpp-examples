#pragma once
struct Stash
{
	int size;
	int quantity;
	int next;
	unsigned char* storage;

	void initialize(int size);
	int add(const void* element);
	void* fetch(int index);
	void inflate(int increase);
	void cleanup();
	int count();
};