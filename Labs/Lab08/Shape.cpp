#include "Shape.h"

ostream& operator << (ostream & os, const Shape& shape ) {
	os << shape.name;
	return os;
}

// TODO::Define the operators required by the templated compare function
bool 
Shape::operator > (const Shape& s) const {
	return getArea() > s.getArea();
}

bool 
Shape::operator == (const Shape& s) const {
	return getArea() == s.getArea();
}
