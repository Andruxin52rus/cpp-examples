#pragma once
class Stash {
private:
	char element_size;
	long long quantity;
	char* storage;
	long long next;
	void inflate(unsigned int increment);
public:
	Stash(char element_size, long long quantity = 0);
	~Stash();
	long long add(void* element);
	void* fetch(long long index);
	long long count();
};
