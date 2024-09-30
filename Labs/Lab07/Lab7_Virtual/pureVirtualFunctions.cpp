#include <cmath>
#include "pureVirtualFunctions.h"

using namespace PVF;

#define PI 3.14159265359

double
Circle::area() {
	return PI * pow(radius,2.0);
}

double
Circle::perimeter() {
	return 2.0 * PI * radius;
}

double
Rectangle::area() {
	return width * height;
}

double
Rectangle::perimeter() {
	return 2.0 * width * height;
}