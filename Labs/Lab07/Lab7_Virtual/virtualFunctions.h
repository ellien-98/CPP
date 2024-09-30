#ifndef VIRTUAL_FUNCTIONS_
#define VIRTUAL_FUNCTIONS_

#include <string>
#include <vector>

namespace VF {
	// Base Class
	class Point {
		// Private variable
		std::string name;
		int x, y;

	public:
		// Constructor
		Point(int newX = 0, int newY = 0, const std::string &newName = "P");
		
		// Copy-Constructor
		Point(const Point& original);
		
		// Destructor
		virtual ~Point ();

		// Set functions
		void setX(int newX) { x = newX; }
		void setY(int newY) { y = newY; }
		// Get functions
		int getX() const { return x; }
		int getY() const { return y; }
		const std::string &getName() { return name; }

		virtual void display() const;
	};

	// Derived Class
	class LabeledPoint : public Point
	{
		// New custom variable
		std::vector<std::string *> labels;
	public:
		// Constructor Declaration
		LabeledPoint(int newX = 0, int newY = 0, const std::string &newName = "P", const std::string & newLabel = "label");
		LabeledPoint(const LabeledPoint& original);
		// Destructor
		~LabeledPoint ();

		// New functions
		void insertLabel(const std::string& newLabel);
		void modifyLabel(unsigned int i, const std::string& newLabel);

		std::string const & getLabel(unsigned int i) const { return *labels[i]; }

		// Overriding Base Class Function
		void display() const;
	};
}

#endif // VIRTUAL_FUNCTIONS_