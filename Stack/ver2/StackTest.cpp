#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test1() {
	Stack st;
	cout << "Count: " << st.count() << endl;
	ifstream in("StackTest.cpp");
	string line;
	while (getline(in, line))
	{
		st.push(new string(line));
		cout << st.count() << " : " << line << endl;
	}
	cout << endl;
	string* line2;
	int count = st.count();
	while (st.count()) {
		line2 = (string*)st.pop();
		cout << st.count() << " : " << *line2 << endl;
	}
	cout << "Count: " << st.count() << endl;
}

void test2() {
	Stack st;
	cout << "Count: " << st.count() << endl;
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
		st.push(&arr[i]);
	}
	cout << "Count: " << st.count() << endl;
	while (st.count()) {
		cout << *(int*)st.pop() << endl;
	}
	cout << "Count: " << st.count() << endl;
}

void test3() {
	Stack st;
	string str[] = { "str1", "str22", "str333" };
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++) {
		st.push(new string(str[i]));
	}
	while (st.count())
	{
		cout << *(string*)st.pop() << endl;
	}
}

void test4() {
	string str[] = { "str1", "str22", "str333" };
	long long length = sizeof(str) / sizeof(*str);
	void** ptrs = new void* [length];
	for (long long i = 0; i < length; i++) {
		ptrs[i] = new string(str[i]);
	}
	Stack st(ptrs, length);

	while (st.count())
	{
		cout << *(string*)st.pop() << endl;
	}

	for (long long i = 0; i < length; i++) {
		delete[] ptrs[i];
	}
	delete[] ptrs;
}

int main() {
	test4();
	system("pause");
}
