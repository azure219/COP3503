#pragma once
#include <iostream>

using namespace std;

template<typename T>

class ABS {

	private:

		float scaleFactor = 2.0;
		int currentSize = 0;
		int maxCapacity = 0;
		T* stack;

	public:

		ABS();
		ABS(int capacity);
		ABS(const ABS& d);
		ABS& operator=(const ABS& d);
		~ABS();

		void push(T data);
		T pop();
		T peek();
		unsigned int getSize();
		unsigned int getMaxCapacity();
		T* getData();
};

// the default constructor
template<typename T>
ABS<T>::ABS() {

	maxCapacity = 1;
	currentSize = 0;
	stack = new T[maxCapacity];
}

// the constructor
template<typename T>
ABS<T>::ABS(int capacity) {

	maxCapacity = capacity;
	currentSize = 0;
	stack = new T[maxCapacity];
}


// the copy constructor
template<typename T>
ABS<T>::ABS(const ABS& d) {

	maxCapacity = d.capacity;
	currentSize = d.currentSize;
	stack = new T[maxCapacity];

	for (int n = 0; n < currentSize; n++) {

		stack[n] = d.stack[n];
	}
}

// the copy assignment operator
template<typename T>
ABS<T>& ABS<T>::operator=(const ABS& d) {

	if (this != &d) {

		maxCapacity = d.capacity;
		currentSize = d.currentSize;
		stack = d.T[maxCapacity];

		for (int n = 0; n < currentSize; n++) {

			stack[n] = d.stack[n];
		}
	}
}

// the destructor
template<typename T>
ABS<T>::~ABS() {

	delete[] stack;
}

template<typename T>
void ABS<T>::push(T data) {

	if (currentSize == maxCapacity) {

		// doubles maxCapacity
		maxCapacity = maxCapacity * scaleFactor;

		// creates temporary stack with bigger capacity
		T* temporaryStack = new T[maxCapacity];    

		// transfers values from old stack to temporary stack
		for (int n = 0; n < currentSize; n++) {

			temporaryStack[n] = stack[n];
		}

		delete[] stack; // deletes old stack
		stack = temporaryStack; // assigns values in temporary stack to new stack

		stack[currentSize] = data; // pushes newly created stack
		currentSize = currentSize + 1; // increases current size by 1

	} else {

		stack[currentSize] = data;
		currentSize = currentSize + 1;
	}
}

template<typename T>
T ABS<T>::pop() {

	if (currentSize == 0) {

		throw runtime_error("Error: stack is empty");

	} else if (((float)(currentSize - 1)/maxCapacity) < (1/scaleFactor)) {

		T topValue = stack[currentSize - 1];

		maxCapacity = maxCapacity / scaleFactor;

		T* temporaryStack = new T[maxCapacity];

		for (int n = 0; n < currentSize - 1; n++) {

			temporaryStack[n] = stack[n];
		}

		delete[] stack;
		stack = temporaryStack;

		currentSize = currentSize - 1;

		return topValue;

	} else {

		T topValue = stack[currentSize - 1];

		T* temporaryStack = new T[maxCapacity];

		for (int n = 0; n < currentSize - 1; n++) {

			temporaryStack[n] = stack[n];
		}

		delete[] stack;
		stack = temporaryStack;

		currentSize = currentSize - 1;

		return topValue;

	}
}

template<typename T>
T ABS<T>::peek() {

	if (currentSize == 0) {

		throw runtime_error("Error: stack is empty");

	} else {

		return stack[currentSize - 1];
	}
}

template<typename T>
unsigned int ABS<T>::getSize() {

	return currentSize;
}

template<typename T>
unsigned int ABS<T>::getMaxCapacity() {

	return maxCapacity;
}

template<typename T>
T* ABS<T>::getData() {

	return stack;
}
