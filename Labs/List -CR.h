#pragma once
#include "ListTraits.h"
#include <iostream>
#include <list>
using namespace std;

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
	}		//mylist.end() Returns an iterator that references a
	 // position past the last element in the list.

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
