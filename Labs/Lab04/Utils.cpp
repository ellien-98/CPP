#include <iostream>
#include <vector>
#include <string>  

void printStringVector (const std::vector<std::string> &vector) {
	// Use an iterator to print the contents of the vector.
	// The iterator is const_iterator which means that we 
	// cannot use it to change the contents of the set.
	std::vector<std::string>::const_iterator cit;
	
	std::cout << std::endl;
	std::cout << "Strings contained in the vector:" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	for (cit = vector.begin(); cit != vector.end(); ++cit) {
		std::cout << *cit << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
}

bool isDigit(const std::string &word) {
	bool retVal = true;

	for(std::string::const_iterator k = word.begin(); k != word.end(); ++k)
		retVal = retVal && isdigit(*k);

	return retVal;
}

int readPosInt ( ) {
	std::string input;
	bool validInput = false;
	std::cout << "Type a positive integer value :: ";
	do {
		std::cin >> input;

		if ( !(validInput = isDigit(input)) ) {
			std::cout << input << " is not a number! Try again.\n";
		}
		else if (atoi(input.c_str()) <= 0) {
				std::cout << input << " Is not a positive integer! Try again\n";
		}
	} while ( !validInput );
	return atoi(input.c_str());
}