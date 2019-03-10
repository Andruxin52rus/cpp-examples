#include <cassert>
#include <vector>
#include "Stash.h";
using namespace std;

const int increment = 100;

void Stash::initialize(int size) {
	this->size = size;
	this->next = 0;
}

int Stash::add(const void* element) {
	char* e = (char*)element;
	for (int i = 0; i < size; i++) {
		storage.push_back(e[i]);
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

}

void Stash::cleanup() {
}