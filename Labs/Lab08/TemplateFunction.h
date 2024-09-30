#ifndef _TEMPLATE_FUNCTION_H_
#define _TEMPLATE_FUNCTION_H_

#include <iostream>

// Templates are defined in header files.
// 
// The templated functions/classes are also defined in the header files.
// 
// There is way to put the implementations in a .cpp file but you could avoid it for now.


// In templates keyword "typename" and "class" are the same
template <typename T> 
// OR totally equivalent 
// template <class T>

// it can compare anything that defines the operators >, ==
void compare(const T &a, const T &b) {
	if (a==b)
		std::cout << a << " is equal to " << b << std::endl;
	else if (a>b)
		std::cout << a << " is bigger than " << b << std::endl;
	else
		std::cout << a << " is smaller than " << b << std::endl;
}

// If we didn't have templates we would have to overload the function for every possible type!!!!
/* Ex.

void compare(const int& a, const int& b) {
	if (a==b)
		std::cout << a << " is equal to " << b << std::endl;
	else if (a>b)
		std::cout << a << " is bigger than " << b << std::endl;
	else
		std::cout << a << " is smaller than " << b << std::endl;
}

void compare(const float& a, const float& b) {
	.
	.
	.
}

void compare(const Object& a, const Object& b) {
	.
	.
	.
}

.
.
.

*/


#endif //_TEMPLATE_FUNCTION_H_