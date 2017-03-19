#include "Stack.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void test1() {
	ifstream in("StackTest.cpp");
	Stack textlines;
	textlines.initialize();
	string line;
	// ������ ����� � ���������� ����� � �����:
	while (getline(in, line))
		textlines.push(new string(line));
	// ���������� ����� �� ����� � �����:
	string* s;
	while ((s = (string*)textlines.pop()) != 0) {
		cout << *s << endl;
		delete s;
	}
	textlines.cleanup();
}

void test2() {

}

int main() {
	test1();
	system("pause");
}
