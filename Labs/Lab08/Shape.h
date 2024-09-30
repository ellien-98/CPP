#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>
#include <iostream>

using namespace std;

//------------------Point2D Class-------------------//
class Point2D{
	float x;
	float y;
public:
	Point2D(float newX, float newY)
		:x(newX), y(newY) { cout << "  - Point Constructor" << endl; };
};

//------------------Shape Class-------------------//
class Shape
{
	string name;
public:
	Shape() { cout << "  - Shape Constructor" << endl; };

	virtual ~Shape() { cout << "  - Shape destructor" << endl; }
	
	void setName(string s) { name = s; }

	virtual void draw () = 0;
	virtual float getArea() const = 0;

	friend ostream& operator << (ostream & os, const Shape& s);

	// TODO:: Declare the operators required by the templated compare function
	bool operator > (const Shape& s) const;
	bool operator == (const Shape& s) const;
};

//------------------Circle Class-------------------//
class Circle : public Shape {
	Point2D center;
	float radius;
public:
	Circle(Point2D c, float r)
		: center(c), radius(r) { cout << "  - Circle Constructor" << endl; };
	virtual ~Circle() { cout<<"  - Circle destructor"<<endl; }

	virtual void draw() { cout << "Drawing a Circle" << endl; }
	virtual float getArea() const { return 3.14f*radius*radius; }
};

//------------------Line Class-------------------//
class Quad : public Shape{
	Point2D center;
	float size;
public:
	Quad(Point2D c, float s) 
		: center(c), size(s) { cout << "  - Quad Constructor" << endl; };
	virtual ~Quad() { cout << "  - Quad destructor" << endl; }

	virtual void draw() { cout << "Drawing a Quad" << endl; }
	virtual float getArea() const { return size*size; }
};

#endif //_SHAPE_H_