#include <iostream>
#include "Stack.h"
using namespace std;

int main(void) {
	Stack<double> myStack;

	for (double value = 0; value < 10; value += 1.1)
	{
		myStack.Push(value);
	}
	while (!myStack.IsEmpty()) {
		cout << myStack.Top() << endl;
		myStack.Pop();
	}

	return 0;
}

