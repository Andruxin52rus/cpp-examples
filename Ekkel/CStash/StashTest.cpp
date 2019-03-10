#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include "Stash.h"
using namespace std;

int main() {
	Stash intStash;
	intStash.initialize(sizeof(int));
	for (int i = 0; i < 100; i++)
		intStash.add(&i);
	for (int j = 0; j < intStash.count(); j++)
		cout << "intStash.fetch(" << j << ") = "
		<< *(int*)intStash.fetch(j)
		<< endl;
	
	Stash stringStash;
	const int bufsize = 80;
	stringStash.initialize(sizeof(char) * bufsize);
	ifstream in("StashTest.cpp");
	string line;
	while (getline(in, line))
		stringStash.add(line.c_str());
	int k = 0;
	char* cp;
	while ((cp = (char*)stringStash.fetch(k++)) != 0)
		cout << "stringStash.fetch(" << k << ") = "
		<< cp << endl;
	intStash.cleanup();
	stringStash.cleanup();
	system("pause");
}
