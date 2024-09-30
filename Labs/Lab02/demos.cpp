#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

#include "utils.h"

using namespace std;

void arrays_and_pointers_demo () {
	int intArray[4] = {1, 2, 3, 4}; //declare and initialize a C array
	int test = 9;
	int *intPointer; //this is a pointer variable, it stores memory addresses pointing to integer values. 
	
	/*
	 * just a quick reminder on pointers
	 * &test is the memory address of variable test. 
	 */
	intPointer = &test;
	
	cout << "Variable test is at the memory adress " << intPointer << 
			" \nand stores an integer with value " << *intPointer << endl << endl;
	
	/*
	 * In C++ an array is just a pointer with pre-allocated memory.
	 * Therefore we can directly do the following:
	 * (because ar is already a memory address, we don't use the & operator)
	 */
	intPointer = intArray;
	
	cout << "The array has the following values: \n";
	for ( int i=0; i<4; i++ ) {
		cout << intArray[i] << endl;
	}

	cout << "\nI can access the same values using the pointer: \n";
	for ( int i=0; i<4; i++ ) {
		cout << intPointer[i] << endl;
	}
		
	cout<<"\nI can also update the values using the pointer: (writing zero)\n";
	for ( int i=0; i<4; i++ ) {
		intPointer[i] = 0;
	}

	cout<<"\nThe values on the array are now : \n";
	for ( int i=0; i<4; i++ ) {
		cout << intArray[i] << endl;
	}


	// Finally a 2D array
	int twoDimArray[4][3] = {{22, 23, 10},
							 {15, 25, 13},
							 {20, 74, 67},
							 {11, 18, 14} };

	// Init the array
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			twoDimArray[i][j] = i*4 + j;
		}
	}

	cout << "Press ENTER to continue to 2D arrays" << endl;
	system ("PAUSE");

	cout << "\nThe 2D array has the following values: \n";
	// Fill the missing code (Using for-loops)
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			cout << twoDimArray[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nAnd now access the 2D array using a pointer: \n";
	intPointer = &twoDimArray[0][0];
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			cout << intPointer[i*3+j] << endl;
		}
	}
		
}


void dynamic_memory_management_demo () {
	std::string input;
	int size;

	bool validInput = false;
	cout << "Type the size of array to allocate :: ";
	do {
		cin >> input;

		if ( !(validInput = isDigit(input)) ) {
			printf ("%s is not a number! Try again.\n", input.c_str());
		}
		
	} while ( !validInput );
	size = atoi(input.c_str());
	
	/*
	 * The C++ way -- new & delete
	 * 
	 * Allocates a new array of integers with the requested size using "new"
	 */
	int* dyn_array=new int[size];
	
	// Fill with some values
	for (int i=0;i<size;i++)
		dyn_array[i]=i*i;
		
	cout << " C++ Dynamic Array Values :: \n";
	for (int i=0;i<size;i++) {
		cout<<dyn_array[i]<<endl;	
	}
	
	// Do not forget to release memory (Dynamic Allocated memory is not released by itself :) )
	// dyn_array is an array so YOU HAVE TO USE delete []
	delete []dyn_array;

	/*
	 * The C way -- malloc & free
	 * 
	 * Allocates a new array of integers with the requested size using "malloc"
	 */
	// From the CPP reference :: void* malloc (size_t size);
	//	-- malloc always returns void * so we cast it to our type (int *)
	//	-- the expected argument is the size of memory we want to allocate in bytes
	//	-- (int *)malloc(4) would allocate 4 bytes --> 1 int !
	//	-- instead of remembering the size of types we use sizeof(type) * times the number we want
	dyn_array = (int *)malloc(sizeof(int)*size);
	
	// Fill with some values
	for (int i=0;i<size;i++)
		dyn_array[i]=i*i;
		
	cout << "\n C Dynamic Array Values :: \n";
	for (int i=0;i<size;i++) {
		cout<<dyn_array[i]<<endl;	
	}
	
	// Do not forget to release memory (Dynamic Allocated memory is not released by itself :) )
	free(dyn_array);

	// ATTENTION -- Never mix "new" with "free" and "malloc" with "delete"
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void vector_demo () {
	// Vectors are containers representing arrays. They change automatically their size as we push back items.
	vector<string> words;
	// In case we know the exact size we will use it is more efficient to reserve the slots
	//words.reserve(100);

	bool finished = false;
	string readString;
	cout << "Write some words (To stop write: END)" << endl;
	do {
		// Standard input stream.
		// It corresponds to the C stream stdin.
		// We can use it to read input from keyboard.
		// Using the >> operator we can retreive formatted data (in our example string)
		// Declared in <iostream>
		cin >> readString;
		//cout << "READ :: " << readString << endl;

		// String comparison. Note that string comparisons are Case Sensitive
		if ( readString.compare("END") != 0 ) {
			// Add item to vector
			words.push_back(readString);
		}
		else {
			// Stop do while
			finished = true;
		}
		//cout << "\tVector Capacity :: " << words.capacity() << endl;
	} while ( !finished );

	printStringVector(words);
}