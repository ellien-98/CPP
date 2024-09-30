#include <iostream>

#include "virtualFunctions.h"

using namespace std;
using namespace VF;

// --------------------------------------------------------- //
// Point Constructor-Destructor & Member Function Definition //
// --------------------------------------------------------- //

// Constructor
Point::Point ( int newX, int newY, const string & newName ) 
	:x(newX), y(newY), name(newName) {
	std::cout << "\t- " << name << " Point Constructor" << std::endl; 
}

// Copy-Constructor
Point::Point (const Point& original)
	:x(original.x), y(original.y), name(original.name+"_CP") {
		std::cout << "\t- " << name << " Point Copy-Constructor" << std::endl; 
}

// Destructor
Point::~Point () { 
	std::cout << "\t- " << name << " Point Destructor" << std::endl; 
}

void
Point::display () const {
		std::cout << "x: " << x << ", y: " << y << std::endl;
}

// ---------------------------------------------------------------------------------- //
// LabeledPoint Constructor-Destructor, Copy-Constructor & Member Function Definition //
// ---------------------------------------------------------------------------------- //

// Constructor
LabeledPoint::LabeledPoint (int newX, int newY, const string &newName, const string& newLabel)
	:Point(newX,newY,newName) {
	cout << "\t- " << getName() << " LabeledPoint Constructor" << std::endl;
	labels.push_back(new string(newLabel));
}

// Copy-Constructor
// TODO: Fix the Copy Constructor so that it Performs Deep-Copy instead of Shallow-Copy
LabeledPoint::LabeledPoint (const LabeledPoint& original)
	:Point(original) {
	//:Point(original), labels(original.labels) {
		cout << "\t- " << getName() << " LabeledPoint Copy-Constructor" << std::endl;
		
	// Deep-Copy of Labels Vector List
	// TODO: Write the code here to Deep-Copy the data of LabeledPoint original to the current object
	vector<string *>::const_iterator cit;
	for (cit = original.labels.begin(); cit != original.labels.end(); ++cit) {
		labels.push_back(new string(*(*cit)));
	}
}

// Destructor
LabeledPoint::~LabeledPoint () { 
	std::cout << "\t- " << getName() << " LabeledPoint Destructor" << std::endl; 
	std::cout << "\t    - Deleting Dynamically Allocated strings..." << endl;
		
	vector<string *>::iterator it;
	for (it = labels.begin(); it != labels.end(); ++it) {
		delete *it;
		*it = NULL;
	}
}

void
LabeledPoint::insertLabel(const std::string& newLabel) {
	labels.push_back(new std::string(newLabel));
}

void
LabeledPoint::modifyLabel(unsigned int i, const std::string& newLabel) {
	if (i >= labels.size() || i < 0) {
		cout << "modifyLabel :: wrong index of label to modify" << endl;
		return;
	}
	*labels[i] = newLabel;
}

void
LabeledPoint::display () const {
	for (unsigned int i=0; i < labels.size(); ++i) {
		cout << "Label " << i << " : " << labels[i]->c_str() << endl;
	}
	// Call Base Class display function to type Base values
	Point::display();
}
