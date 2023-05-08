#pragma once
#include <iostream>

using namespace std;

template<typename T>

class ABQ {

private:

	float scaleFactor = 2.0;
	int currentSize = 0;
	int maxCapacity = 0;
	T* queue;

public:

	ABQ();
	ABQ(int capacity);
	ABQ(const ABQ& d);
	ABQ& operator = (const ABQ& d);
	~ABQ();

	void enqueue(T data);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
};

// the default constructor
template<typename T>
ABQ<T>::ABQ() {

	maxCapacity = 1;
	currentSize = 0;
	queue = new T[maxCapacity];
}

// the constructor
template<typename T>
ABQ<T>::ABQ(int capacity) {

	maxCapacity = capacity;
	currentSize = 0;
	queue = new T[maxCapacity];
}


// the copy constructor
template<typename T>
ABQ<T>::ABQ(const ABQ& d) {

	maxCapacity = d.capacity;
	currentSize = d.currentSize;
	queue = new T[maxCapacity];

	for (int n = 0; n < currentSize; n++) {

		queue[n] = d.queue[n];
	}
}

// the copy assignment operator
template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& d) {

	if (this != &d) {

		maxCapacity = d.capacity;
		currentSize = d.currentSize;
		queue = d.T[maxCapacity];

		for (int n = 0; n < currentSize; n++) {

			queue[n] = d.queue[n];
		}
	}
}

// the destructor
template<typename T>
ABQ<T>::~ABQ() {

	delete[] queue;
}

template<typename T>
void ABQ<T>::enqueue(T data) {

	if (currentSize == maxCapacity) {

		// doubles maxCapacity
		maxCapacity = maxCapacity * scaleFactor;

		// creates temporary stack with bigger capacity
		T* temporaryQueue = new T[maxCapacity];

		// transfers values from old stack to temporary stack
		for (int n = 0; n < currentSize; n++) {

			temporaryQueue[n] = queue[n];
		}

		delete[] queue; // deletes old stack
		queue = temporaryQueue; // assigns values in temporary stack to new stack

		queue[currentSize] = data; // pushes newly created stack
		currentSize = currentSize + 1; // increases current size by 1

	} else {

		queue[currentSize] = data;
		currentSize = currentSize + 1;
	}
}

template<typename T>
T ABQ<T>::dequeue() {

	T topValue;

	if (currentSize == 0) {

		throw runtime_error("Error: stack is empty");

	} 
	
	if (((float)(currentSize - 1) / maxCapacity) < (1.0 / scaleFactor)) {

		topValue = queue[0];
		currentSize = currentSize - 1;

		for (int n = 0; n < currentSize; n++) {

			queue[n] = queue[n + 1];
		}

		T* temporaryQueue = new T[maxCapacity];

		maxCapacity = maxCapacity / scaleFactor;

		for (int n = 0; n < currentSize; n++) {

			temporaryQueue[n] = queue[n];
		}

		delete[] queue;
		queue = temporaryQueue;
		
		return topValue;

		currentSize = currentSize - 1;

		return topValue;

	} else {

		topValue = queue[0];
		for (int n = 0; n < currentSize; n++) {

			queue[n] = queue[n + 1];
		}

		currentSize = currentSize - 1;
		return topValue;

	}
}

template<typename T>
T ABQ<T>::peek() {

	if (currentSize == 0) {

		throw runtime_error("Error: stack is empty");

	}
	else {

		return queue[0];
	}
}

template<typename T>
unsigned int ABQ<T>::getSize() {

	return currentSize;
}

template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {

	return maxCapacity;
}

template<typename T>
T* ABQ<T>::getData() {

	return queue;
}