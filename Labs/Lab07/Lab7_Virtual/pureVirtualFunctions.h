#ifndef PURE_VIRTUAL_FUNCTIONS_
#define PURE_VIRTUAL_FUNCTIONS_

#include <string>
#include <vector>

namespace PVF {
	// Classes Containing Pure Virtual Functions are Abstract Classes
	class Shape {
		std::string name;
	public:
		Shape (const std::string &newName): name(newName) {}
		virtual ~Shape() {}

		// Pure Virtual Functions
		virtual double area() = 0;
		virtual double perimeter() = 0;

		const std::string &getName() { return name; }
	};

	// Circle Class
	class Circle: public Shape {
		double radius;
	public:
		Circle (const std::string &newName, double newRadius)
			: Shape(newName), radius(newRadius) {}
		~Circle() {}
		double area();
		double perimeter();
	};

	class Rectangle: public Shape {
		double width;
		double height;

	public:
		Rectangle (const std::string &newName, double newWidth, double newHeight)
			: Shape(newName), width(newWidth), height(newHeight) {}
		~Rectangle() {}
		double area();
		double perimeter();
	};
}

#endif //PURE_VIRTUAL_FUNCTIONS_