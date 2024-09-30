#include <iostream>
#include <vector>
#include <string>  


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