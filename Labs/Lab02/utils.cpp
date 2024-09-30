#include <iostream>
#include <vector>
#include <string>  

void printStringVector(std::vector<std::string> &vector) {
	// Use an iterator to print the contents of the vector.
	// The iterator is const_iterator which means that we 
	// cannot use it to change the contents of the set.
	std::vector<std::string>::const_iterator cit;
	
	std::cout << std::endl;
	std::cout << "Strings contained in the vector:" << std::endl;
	std::cout << "--------------------------------" << std::endl;

#if 1	// PRE-PROCESSOR DIRECTIVE 1st Level
	for (cit = vector.begin(); cit != vector.end(); ++cit) {
		std::cout << *cit << std::endl;
	}
#else	// PRE-PROCESSOR DIRECTIVE 1st Level
	#if 1	// PRE-PROCESSOR DIRECTIVE 2nd Level (Nested)
		// Another way to iterate through the items of the vector
		for (unsigned int i = 0; i < vector.size(); ++i) {
			std::cout << vector[i] << std::endl;
		}
	#else	// PRE-PROCESSOR DIRECTIVE 2nd Level (Nested)
		// Another way to iterate through the items using a pointer!
		// Declare a string pointer variable and get the address that points at the start of the string array
		std::string* pointer_to_string=&(vector[0]);

		for (unsigned int i = 0; i < vector.size(); ++i, pointer_to_string++) {
			std::cout << *pointer_to_string << std::endl;
			// Using the pointer we could also change the values of the vector!
			//*pointer_to_string = "Anthousis";
			//std::cout << vector[i] << std::endl;
		}
	#endif	// PRE-PROCESSOR DIRECTIVE 2nd Level (Nested)
#endif	// PRE-PROCESSOR DIRECTIVE 1st Level

	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	
}

bool isDigit(std::string &word) {
	bool retVal = true;

	for(std::string::const_iterator k = word.begin(); k != word.end(); ++k)
		retVal = retVal && isdigit(*k);

	return retVal;
}