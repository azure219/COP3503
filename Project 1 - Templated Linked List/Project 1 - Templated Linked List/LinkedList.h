#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList { // [<-- 1 -->] [<-- 2 -->] [<-- 3 -->] [<-- 4 -->] [<-- 5 -->] 

public:

	// node class
	class Node {

	public:

		T data;
		Node* next;
		Node* prev;

	};

	// essentials
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
	~LinkedList();

	// ways to add information (insertion)
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);

	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);


	// ways to get information about container (accessors)
	unsigned int NodeCount() const;

	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;
	Node* GetNode(unsigned int index);
	const Node* GetNode(unsigned int index) const;
	Node* Find(const T& data);
	const Node* Find(const T& data) const;
	void FindAll(vector<Node*>& outData, const T& value) const;

	// ways to remove data in container (removal)
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T&data);
	bool RemoveAt(unsigned int index);
	void Clear();

	// ways to see data in container (behaviors)
	void PrintForward() const;
	void PrintReverse() const;

	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	// (operators)
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	bool operator==(const LinkedList<T>& rhs) const;

private:

	unsigned int nodeCounter;
	Node* head; // pointer to the first node in the linked list
	Node* tail; // pointer to the last node in the linked list
	Node* next; // pointer to the next node
	Node* prev; // pointer to the previous node
	Node* temporaryNode; // temporary node pointer

};

// default constructor
template<typename T>
LinkedList<T>::LinkedList() {

	nodeCounter = 0;
	head = nullptr;
	tail = nullptr;

}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {

	head = nullptr;
	tail = nullptr;

	Node* newList = list.head;

	while (newList != nullptr) {

		LinkedList::AddTail(newList->data);
		newList = newList->next;

	}

}

// copy assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {

	Node* deleteNode = head; // assigns temporary node deleteNode to head

	while (deleteNode != nullptr) { // runs until there are no more nodes in the linked list

		Node* toDelete = deleteNode; // assigns deleteNode to toDelete which is actually deleted
		deleteNode = deleteNode->next; // shifts deleteNode to next node in linked list
		delete toDelete; // deletes toDelete

	}

	head = nullptr;
	tail = nullptr;

	Node* newList = rhs.head;

	while (newList != nullptr) {

		LinkedList::AddTail(newList->data);
		newList = newList->next;

	}

	return *this;

}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {

	Node* deleteNode = head; // assigns temporary node deleteNode to head

	while (deleteNode != nullptr) { // runs until there are no more nodes in the linked list

		Node* toDelete = deleteNode; // assigns deleteNode to toDelete which is actually deleted
		deleteNode = deleteNode->next; // shifts deleteNode to next node in linked list
		delete toDelete; // deletes toDelete

	}
}

template<typename T>
void LinkedList<T>::AddHead(const T& data) { // 

	temporaryNode = new Node(); // creates temporary node, aka new node to be added
	temporaryNode->data = data; // assigns temporary node its data value

	if (head == nullptr) { // if head == nullptr, there's only 1 node in the linked list

		head = temporaryNode; // because there's only 1 node, head/tail are both just temporaryNode (data)
		tail = temporaryNode; // ^^^

		temporaryNode->next = nullptr; // because there's only 1 node, next/previous are nullptr by default 
		temporaryNode->prev = nullptr; // ^^^

	} else { // there's more than 1 node in the linked list

		head->prev = temporaryNode; // previous to head (left) is temporaryNode (list shifts rightwards)
		temporaryNode->next = head; // next to temporaryNode (right) is head
		head = temporaryNode; // temporaryNode becomes new head (at the very left)

	}

	nodeCounter++; // number of nodes in the list increases by 1

}

template<typename T>
void LinkedList<T>::AddTail(const T& data) { // exact same logic as AddHead but inverted

	temporaryNode = new Node();
	temporaryNode->data = data;

	if (tail == nullptr) {

		head = temporaryNode;
		tail = temporaryNode;

		temporaryNode->next = nullptr;
		temporaryNode->prev = nullptr;

	}
	else {

		tail->next = temporaryNode;
		temporaryNode->prev = tail;
		tail = temporaryNode;

	}

	nodeCounter++;

}

template<typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) { // given array & count, creates a linked list for data

	int a = count - 1;

	for (int n = 0; n < (int)count; n++) {

		int i = a - n;

		AddHead(data[i]); // uses AddHead to create the linked list from  given array up to given count
	}

}

template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) { // same as AddNodesHead but using AddTail

	for (int n = 0; n < (int)count; n++) {

		AddTail(data[n]);

	}
}

template<typename T>
unsigned int LinkedList<T>::NodeCount() const {

	return nodeCounter; // returns nodeCounter aka size of linked list
}

template<typename T>
void LinkedList<T>::PrintForward() const { // same logic as destructor except to print

	Node* printNode = head;

	while (printNode != nullptr) {

		cout << printNode->data << endl;
		printNode = printNode->next;

	}
}

template<typename T>
void LinkedList<T>::PrintReverse() const { // same logic as PrintForward except inverted

	Node* printNode = tail;

	while (printNode != nullptr) {

		cout << printNode->data << endl;
		printNode = printNode->prev;

	}

}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {

	return head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {

	return head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {

	return tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {

	return tail;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {

	Node* returnNode = nullptr;

	if (index > (nodeCounter - 1)) {

		throw out_of_range("error");

	} else if (index == 0) {

		return head;

	} else {

		returnNode = head; // assigns node to be returned, returnNode to nullptr

		for (int n = 0; n < index; n++) {

			returnNode = returnNode->next; // shifts deleteNode to next node in linked list
		}
	}

	return returnNode;

}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {

	Node* returnNode = nullptr;

	if (index > (nodeCounter - 1)) {

		throw out_of_range("error");

	} else if (index == 0) {

		return head;

	} else {

		returnNode = head; // assigns node to be returned, returnNode to nullptr

		for (unsigned int n = 0; n < index; n++) {

			returnNode = returnNode->next; // shifts deleteNode to next node in linked list
		}
	}

	return returnNode;

}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {

	Node* returnNode = head; // assigns temporaryNode to head

	while (returnNode != nullptr) { // runs until there are no more nodes in the linked list

		if (returnNode->data == data) {

			return returnNode;

		}

		returnNode = returnNode->next; // shifts deleteNode to next node in linked list

	}

	return nullptr;

}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {

	Node* returnNode = head; // assigns temporaryNode to head

	while (returnNode != nullptr) { // runs until there are no more nodes in the linked list

		if (returnNode->data == data) {

			return returnNode;

		}

		returnNode = returnNode->next; // shifts deleteNode to next node in linked list

	}

	return nullptr;

}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {

	Node* saveNode = head; // assigns temporaryNode to head

	while (saveNode != nullptr) { // runs until there are no more nodes in the linked list

		if (saveNode->data == value) {

			outData.push_back(saveNode);

		}

		saveNode = saveNode->next; // shifts deleteNode to next node in linked list

	}

}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index) {

	Node* returnNode = nullptr;

	if (index > (nodeCounter - 1)) {

		throw out_of_range("error");

	} else if (index == 0) {

		return head->data;

	} else {

		Node* returnNode = head; // assigns node to be returned, returnNode to nullptr

		for (int n = 0; n < index; n++) {

			returnNode = returnNode->next; // shifts deleteNode to next node in linked list
		}
	}

	return returnNode->data;

}

template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {


	Node* returnNode = nullptr;

	if (index > (nodeCounter - 1)) {

		throw out_of_range("error");

	} else if (index == 0) {

		return head->data;

	} else {

		Node* returnNode = head; // assigns node to be returned, returnNode to nullptr

		for (int n = 0; n < index; n++) {

			returnNode = returnNode->next; // shifts deleteNode to next node in linked list
		}
	}

	return returnNode->data;


}

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {

	Node* toAdd = new Node; // creates new Node to be added, toAdd
	toAdd->prev = node; // toAdd's previous node is passed node
	toAdd->data = data; // toAdd's data is passed data

	if (node == tail) {

		AddTail(data); // if node == tail add new tail by calling AddTail function

	} else {

		Node* oldNext = node->next; // oldNext is equal to passed node's old next node
		oldNext->prev = toAdd; // oldNext's previous is equal to toAdd
		toAdd->next = oldNext; // toAdd's next is oldNext
		node->next = toAdd; // passed node's next is new next node, toAdd

	}

	nodeCounter++;

}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	
	Node* toAdd = new Node; // creates new Node to be added, toAdd
	toAdd->next = node; // toAdd's previous node is passed node
	toAdd->data = data; // toAdd's data is passed data

	if (node == head) {

		AddHead(data); // if node == tail add new tail by calling AddTail function

	} else {

		Node* oldNext = node->prev; // oldNext is equal to passed node's old next node
		oldNext->next = toAdd; // oldNext's previous is equal to toAdd
		toAdd->prev = oldNext; // toAdd's next is oldNext
		node->prev = toAdd; // passed node's next is new next node, toAdd

	}

	nodeCounter++;

}

template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {

	if (index > nodeCounter) {

		throw out_of_range("error");

	} else if (index == 0) {

		AddHead(data);

	} else if (index == nodeCounter) {

		AddTail(data);

	} else {

		Node* before = head; 

		for (unsigned int n = 1; n < index; n++) {

			before = before->next; // shifts before to next node in linked list until it is at the index passed

		}

		Node* toAdd = new Node; // creates new Node to be added, toAdd
		toAdd->data = data; // toAdd's data is passed data

		Node* oldNext = before->next; // oldNext is equal to passed node's old next node

		oldNext->prev = toAdd; // oldNext's previous is equal to toAdd
		toAdd->next = oldNext; // toAdd's next is oldNext
		before->next = toAdd; // passed node's next is new next node, toAdd

		nodeCounter++;

	} 

}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {

	Node* testNode = head;

	if (rhs.nodeCounter == nodeCounter) {

		for (unsigned int n = 0; n < nodeCounter; n++) {

			if (testNode->data != rhs.GetNode(n)->data) {

				return false;

			} 

			testNode = testNode->next;
		}

		return true;

	} else {

		return false;

	}
}

template<typename T>
bool LinkedList<T>::RemoveHead() {

	if (nodeCounter == 0) {

		return false;

	} else if (nodeCounter == 1) {

		delete head;

		head = nullptr;
		tail = nullptr;
		nodeCounter--;

		return true;

	} else {

		Node* Next = head->next;
		Next->prev = nullptr;

		delete head;
		head = Next;
		nodeCounter--;

		return true;

	}

}

template<typename T>
bool LinkedList<T>::RemoveTail() {

	if (nodeCounter == 0) {

		return false;

	} else if (nodeCounter == 1) {

		delete tail;

		head = nullptr;
		tail = nullptr;
		nodeCounter--;

		return true;

	} else {

		Node* Previous = tail->prev;
		Previous->next = nullptr;

		delete tail;
		tail = Previous;
		nodeCounter--;

		return true;

	}

}

template<typename T>
unsigned int LinkedList<T>::Remove(const T& data) {

	unsigned int numDeleted;
	vector<LinkedList<T>::Node*> nodesToDelete;
	FindAll(nodesToDelete, data);

	for (numDeleted = 0; numDeleted < nodesToDelete.size(); numDeleted++) {

		Node* toDelete = nodesToDelete[numDeleted]; // assigns deleteNode to toDelete which is actually deleted
		
		Node* Previous = toDelete->prev;
		Node* Next = toDelete->next;

		Previous->next = Next;
		Next->prev = Previous;
		
		delete toDelete; // deletes toDelete

	}

	return numDeleted;

}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {

	if (index > nodeCounter - 1) {

		return false;

	} else if (index == 0) {

		RemoveHead();
		nodeCounter--;
		return true;

	} else if (index == nodeCounter - 1) {

		RemoveTail();
		nodeCounter--;
		return true;

	} else {

		Node* toDelete = head;

		for (unsigned int n = 0; n < index; n++) {

			toDelete = toDelete->next; // shifts before to next node in linked list until it is at the index passed

		}

		Node* Previous = toDelete->prev;
		Node* Next = toDelete->next;

		Previous->next = Next;
		Next->prev = Previous;

		delete toDelete; // deletes toDelete

		nodeCounter--;
		return true;

	}

}

template<typename T>
void LinkedList<T>::Clear() {

	Node* deleteNode = head; // assigns temporary node deleteNode to head

	while (deleteNode != nullptr) { // runs until there are no more nodes in the linked list

		Node* toDelete = deleteNode; // assigns deleteNode to toDelete which is actually deleted
		deleteNode = deleteNode->next; // shifts deleteNode to next node in linked list
		delete toDelete; // deletes toDelete

	}

	head = nullptr;
	tail = nullptr;
	nodeCounter = 0;

}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {

	if (node == nullptr) {

		return;

	} else {

		cout << node->data << endl;

		PrintForwardRecursive(node->next);

	}

}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {

	if (node == nullptr) {

		return;

	} else {

		cout << node->data << endl;

		PrintReverseRecursive(node->prev);

	}

}