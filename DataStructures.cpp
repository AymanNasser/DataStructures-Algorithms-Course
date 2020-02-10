//============================================================================
// Name        : DataStructures.cpp
// Author      : An
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Arr_stack.h"

using namespace std;

void display(int c)
{
	cout << c << "\t";

}

int main() {
	int x[5],z;
	Stack s;
	createStack(&s);
	for (int var = 0; var < 5; ++var) {
		cin >> x[var];
		pushStack(x[var],&s);
	}

	cout << stackSize(&s) << endl;
	popStack(&z,&s);
	traverseStack(&s,display);
	cout << endl << z << endl;
	cout << stackSize(&s) << endl;

	popStack(&z,&s);
	cout << endl << z << endl;
		cout << stackSize(&s) << endl;

	return 0;
}
