#include "Stash.h"
#include <cassert>

Stash::Stash(char element_size, long long quantity) {
	this->element_size = element_size;
	this->quantity = quantity;
	this->next = 0;
	this->storage = new char[this->quantity * this->element_size];
}

Stash::~Stash() {
	delete[] this->storage;
}


long long Stash::add(void* element) {
	if (this->next >= this->quantity) this->inflate(100);
	char* e = (char*)element;
	long long start_bytes = this->next * this->element_size;
	for (char i = 0; i < this->element_size; i++) {
		storage[start_bytes + i] = e[i];
	}
	this->next++;
	return (next - 1);
}

void* Stash::fetch(long long index) {
	assert(index >= 0);
	if (index >= next) return 0;
	return &(this->storage[index * this->element_size]);
}

void Stash::inflate(unsigned int increment) {
	int new_quantity = this->quantity + increment;
	char* new_storage = new char[new_quantity * this->element_size];
	for (long long i = 0; i < this->quantity * element_size; i++) {
		new_storage[i] = storage[i];
	}
	delete[] storage;
	storage = new_storage;
	this->quantity = new_quantity;
}

long long Stash::count() {
	return this->next;
}
