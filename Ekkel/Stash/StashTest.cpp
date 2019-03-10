#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include "Stash.h"
using namespace std;

int main() {
	Stash st(sizeof(int));
	for (int i = 0; i < 100; i++)
		st.add(&i);
	for (int j = 0; j < st.count(); j++)
		cout << "intStash.fetch(" << j << ") = "
		<< *(int*)st.fetch(j)
		<< endl;

	const int bufsize = 80;
	Stash stringStash(sizeof(char) * bufsize);
	ifstream in("StashTest.cpp");
	string line;
	while (getline(in, line))
		stringStash.add((char*)line.c_str());
	int k = 0;
	char* cp;
	while ((cp = (char*)stringStash.fetch(k++)) != 0)
		cout << "stringStash.fetch(" << k << ") = "
		<< cp << endl;
	system("pause");
}
