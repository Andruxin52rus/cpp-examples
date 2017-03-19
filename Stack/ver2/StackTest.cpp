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

int main() {
	test2();
	system("pause");
}
