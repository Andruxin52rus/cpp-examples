#include <cassert>
#include <vector>
#include "Stash.h";
using namespace std;

const int increment = 100;

void Stash::initialize(int size) {
	this->size = size;
	this->quantity = 0;
	this->next = 0;
	this->storage = 0;
}

int Stash::add(const void* element) {
	if (next >= quantity) inflate(increment);
	int start_bytes = size * next;
	unsigned char* e = (unsigned char*)element;
	for (int i = 0; i < size; i++) {
		storage[start_bytes + i] = e[i];
	}
	next++;
	return next - 1;
}

void* Stash::fetch(int index) {
	assert(index >= 0);
	if (index >= next) return 0;
	return &(storage[index * size]);
}

int Stash::count() {
	return next;
}

void Stash::inflate(int increment) {
	assert(increment > 0);
	int new_quantity = quantity + increment;
	int new_bytes = new_quantity * size;
	int old_bytes = quantity * size;
	unsigned char* block = new unsigned char[new_bytes];
	for (int i = 0; i < old_bytes; i++) {
		block[i] = storage[i];
	}
	delete[] storage;
	storage = block;
	quantity = new_quantity;
}

void Stash::cleanup() {
	delete[] storage;
}
