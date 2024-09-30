#include <iostream>
#include "MultipleInheritance.h"

using namespace std;

void multiple_inheritance_demo ( );

void (* fp) (void);

int main ( int argc, char *argv[] ) {
	fp = multiple_inheritance_demo;
	
	fp();

	system ("pause");
	return 0;
}

void multiple_inheritance_demo (void) {
	cout << "Creating a Car\n--------------" << endl;
	Car zastava("Zastava 101",			// Name
				4,						// Capacity
				4,						// Wheels
				5);						// Doors
	cout << "Created Car with name :: " << zastava.getName() << endl;

	cout << "\nCreating an Airplane\n--------------" << endl;
	Airplane boeing747("Boeing 747",	// Name
					   1000,			// Capacity
					   18,				// Wheels
					   4,				// Engines
					   3);				// Pilots
	// TODO:: Fix the Inherince so that Airplane has only one instance of Vehicle class
	//        -- Comment the following line and uncomment the next one
	//cout << "Created Airplane with name :: " << boeing747.Air::getName() << endl;
	cout << "Created Airplane with name :: " << boeing747.getName() << endl;
}
