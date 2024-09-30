#include <iostream>

#include "utils.h"
#include "demos.h"

using namespace std;

// Forward Declaration
void pass_by_val_ref_and_ptr_demo();

///////////////////////////////////////
// Main Function -- code entry point //
// EXECUTION ALWAYS STARTS FROM HERE //
///////////////////////////////////////
int main (int argc, char *argv[]) {

	/* 
	 * Just a print out of the command line arguments
	 * How to add command line arguments in Visual Studio ::
	 *		-- Right Click on Project (Lab2 in this case) in the "Solution Explorer" (usually the most left tab/window)
	 *		-- In the "Configuration Properties" tree menu select the "Debugging"
	 *		-- In the left part of the window insert command line arguments in the "Command Arguments" field
	 *		-- NOTE:: Project Properties are unique per Configuration (Release-Debug)
	 *		--		  That means that if you are in Debug mode and enter command line arguments
	 *		--		  When you change to Release you have to pass them again.
	 *		--		  That goes for everything you do in Project Properties (Additional Include Paths, Libraries etc)
	 */
	for (int i=0; i<argc; ++i) {
		printf ("CMD Line Argument %d is :: %s\n",i, argv[i]);
	}
	printf ("\n");

	/* 
	 * Example of Pass by Value
	 *			  Pass by Reference
	 *			  Pass by Pointer
	 */
	pass_by_val_ref_and_ptr_demo();

	/* 
	 * Example of Arrays and Pointers
	 */
	//arrays_and_pointers_demo();

	/*
	 * Dynamic Allocations ( C & C++ way )
	 */
	//dynamic_memory_management_demo();

	//vector_demo();

	system ("PAUSE");
	return 0;
}

// No need to Forward Declare these functions as they are called after their definition

//Variables are passed by VALUE
void swap1(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
}

//Variables are passed by POINTER
void swap2(int* a, int* b){
	// Fill the missing code
	// HINT in order to access the value "pointed" by the pointer
	//      we have to dereference using "*"
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//Variables are passed by REFERENCE
void swap3(int& a, int& b){
	// Fill the missing code
	int tmp = a;
	a = b;
	b = tmp;
}

// This one needs to be Forward Declared as it is called by main which is 
// on top of this file
void pass_by_val_ref_and_ptr_demo () {
	int x = 3;
	int y = 6;
	cout << "Initial Values\n";
	cout << "x = " << x << " | y = " << y << endl;
	
	swap1(x,y);
	cout << "\nAfter Pass-By-Value Swap\n";
	cout << "x = " << x << " | y = " << y << endl;
	
	// In order to pass by pointer we have to use the address of the variable by using "&"
	swap2(&x,&y);
	cout << "\nAfter Pass-By-Pointer Swap\n";
	cout << "x = " << x << " | y = " << y << endl;
	
	swap3(x,y);
	cout << "\nAfter Pass-By-Reference Swap\n";
	cout << "x = " << x << " | y = " << y << endl;


}

