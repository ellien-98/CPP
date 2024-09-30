#pragma once

#include "ListTraits.h"
//#include <vector>
#include <iostream>
#include <list>
#include <iterator> 
using namespace std;


template <typename T>
struct Node {
	T data;	///*const*//* T data;
	struct Node* next; //struct Node const* const next;

};


template <typename T>
class List : public ListTraits<T>, public ListTraitsExtended<T> {

	Node<T> *head = nullptr;	//c++11
	Node<T> *tail = nullptr;
	

	//List<T> mylist;
	typename List<T>::iterator iter;

public:

	
	void print();
	//void insertBegin(const T& dataIn);
	bool isEmpty();
	unsigned int counter = 0;
	ListTraits<T>& insert(const T& item) override{
		if (isEmpty()) //if there is no nodes in the list simply insert at beginning
		{
			Node<T>* newPtr = new Node(item); //creates new node
			head = newPtr; //start and end pointer are same becuase there is only one object in list
			tail = newPtr;
			counter++;
			return *this;
		}
		else //otherwise
		{
			if (item < head->data) //if the data of the new object is less than than the data of first node in list insert at beginning
			{
				Node<T>* newPtr = new Node<T>(item);
				newPtr->next = head; //the next pointer of the new node points to the node that was previously first
				tail = newPtr; //the pointer for the new node is now the starting node
				counter++;
				return *this;
			}
			else if (item >= tail->data) //if the data of the new object is greater than than the data of last node in list insert at end
			{
				Node<T>* newnextptr = new Node<T>(item);
				tail->next = newnextptr; //the current last node's next pointer points to the new node
				tail = newnextptr; //the new node is now the last node in the list
				counter++;
				return *this;
			}
			else //the new node is being inserted in order but not at the beginning or end
			{
				Node<T>* currentPtr = head;
				Node<T>* newPtr = new Node<T>(item); //creates new node
				while (currentPtr != tail) //runs until the end of the list is reached
				{
					if ((newPtr->data < currentPtr->next->data) && (newPtr->data >= currentPtr->data)) //if the data of the new node is less the data in the next node and greater than the data in the current node, insert after current node 
					{
						Node<T>* nextptr = currentPtr->next;
						currentPtr->next = newPtr; //current nodes next pointer now points to the new node
						newPtr->next = nextptr; //the new nodes next pointer now points the node previously after the current node
						counter++;
						return *this;
						//break;
					}
					currentPtr = currentPtr->next; //moves to the next node in the list
				}
			}
		}
	}
		

	unsigned int size() {
		return counter;
	}
	
	//void print() {}
	
	
	const T* getCurrentElement() const override {
		
	}
	void advance() override {
		
	}
	void rewind() override {
		
	}
	

};

template <typename T>
List<T>::List() //creates list with start and end as NULL
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::~List()
{
	if (!isEmpty()) // List is not empty
	{
		Node<T>* currentPtr = head;
		Node<T>* tempPtr;

		while (currentPtr != 0) // delete remaining nodes
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
}

template <typename T>
void List<T>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		Node<T>* currentPtr = head;
		cout << "The contents of the list is: ";
		while (currentPtr != NULL) //prints until the end of the list is reached
		{
			cout << currentPtr->data << ' ';
			currentPtr = currentPtr->next; //moves to next node in list
		}
		cout << endl;
	}
}


template <typename T>
bool List<T>::isEmpty()
{
	if (head == nullptr && tail == nullptr) //if the start pointer and end pointer are NULL then the list is empty
		return 1;
	else
		return 0;
}


/* WITHOUT STL
//Constructor
	//List(T& thehead, T& thetail, unsigned int& count) : head(thehead),
		//tail(thetail), counter(count)
	//{
	//}
	//List() : head(NULL) {
	//}
	/*
	//Destructor
	~List(){
		while (head)
		{
			Node<T>* tmp = head; // need a copy of pointer
			head = head->next;   // need to advance BEFORE deleting
			delete tmp;          // now can delete safely
		}

		//delete[] * mylist;
	}
	*/
	/*						//list must be sorted
		ListTraits<T>::ListTraits& insert(const T& item) override {
			Node<T>* nod = new Node<T>(item);		//swsto
			Node<T>* current;
			if (*head == nullptr ||
				(*head)->data >= nod->data) {
				nod->next = *head;
				*head = nod;
				this.counter += ;
				return nod;
			}
			else {
				current = *head;
				while (current->next != nullptr
					&& current->next->data
					< new_node->data) {
					current = current->next;
				}
				nod->next = current->next;
				current->next = nod;
				this.counter += ;
				return nod;
			}
		}
		*/
/*//node as http://www.cplusplus.com/articles/E3wTURfi/
template <typename T>
class Node {
//public:
	//T data;
	//Node* next;
	friend class List<T>;

public:
	Node(T);
	T getData();

private:
	T data; //templatized data stored in node
	Node* next; //pointer to the next node in list
};
template <typename T>
Node<T>::Node(T dataIn)
{
	data = dataIn; //stores data in node
	next = 0; //initializes point to next node to null
}
template <typename T>
T Node<T>::getData() //returns data stored in node
{
	return data;
}


*/

/*
*	WITHOUT STL LIBRARY
* 
this is for ListTraits& insert(const T& item) function
* Node<T>* nod = new Node<T>(item);		//swsto
		Node<T>* current;
		if (*head == nullptr || (*head)->data
			>= nod->data) {
			nod->next = *head;
			*head = nod;
			this.counter += ;
			return nod;
		}
		else {
			current = *head;
			while (current->next != nullptr
				&& current->next->data
				< new_node->data) {
				current = current->next;
			}
			nod->next = current->next;
			current->next = nod;
			this.counter += ;
			return nod;
		}
------------------
Node<T>* n = new Node<T>(item);
		Node<T>* temp = head;
		while (temp->next) {
			if (temp->data == item->data) {

				return ;
			}
			else {
				temp = temp->next;
			}
		}
		delete temp;

		Node<T>* n = new Node<T>();
		n->data = item;
		n->next = head;
		head = n;
		counter++;
-----


*/

/*
STL LIBRARY: 
template <typename T>
class List : public ListTraits<T>, public ListTraitsExtended<T> {


	list<T> mylist;
	typename list<T>::iterator iter;

public:

	unsigned int size() {
		return mylist.size();
	}

	ListTraits<T>& insert(const T& item) {
		mylist.push_back(item);
		mylist.sort();
		return *this;
	}

	void print() {
		for (T n : mylist) {
			std::cout << n << " ";
		}
		cout << endl;
	}

	const T* getCurrentElement() const {
		if (iter != mylist.end()) { return &(*iter); }
		return nullptr;
	}

	void advance() {
		iter++;
	}

	void rewind() {
		iter = mylist.begin();
	}

	typename std::list<T>::iterator begin() {
		return mylist.begin();
	}

	typename std::list<T>::iterator end() {
		return mylist.end();
	}
};

*/
