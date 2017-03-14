#pragma once
#include <vector>

struct Stash
{
	int size;
	int next;
	std::vector<char> storage;

	void initialize(int size);
	int add(const void* element);
	void* fetch(int index);
	void inflate(int increase);
	void cleanup();
	int count();
};
