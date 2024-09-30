#ifndef _MULTIPLE_INHERITANCE_H_
#define _MULTIPLE_INHERITANCE_H_

#include <string>

/* 
 * The Diamong Problem
 *
 * Let 2 classes (B, C) that derive from the same class (A)
 * If we define a new class D that derives from both B, C.
 * D class will inherit A class 2 times
 *
 * A	 A
 * |	 |
 * B	 C
 * \	 /
 *	  D
 *
 * If we wanted to refer to a method of A (let f()) from an object 
 * of D (let obj), there is an ambiguity as to which of the two A we
 * refer to. ex: 
 * obj.f(); // causes compilation error
 * It can be solved either by directly specifying to which
 * class we refer. ex:
 * obj.A::f(); // or obj.B::f();
 *
 * This ambiguity can be avoided by declaring that B and C virtually inherit
 * class A. ( class B: public virtual A {} AND class C: public virtual C {}
 *
 *    A
 * /	 \
 * B	 C
 * \	 /
 *	  D
 *
 * now you can just call
 * obj.f();
 * and since D has only one instance of A everything works fine
 *
 * NOTE:: The call to the base class constructor now has to be performed
 * from the last class that inherits it, thus D. Otherwise the default
 * constructor of A will be called and any call to another constructor 
 * of A from B and C are ignored.
 * 
 */

// Base Class
class Vehicle {
	std::string name_;
	short capacity_;

public:
	Vehicle () { name_ = "test"; std::cout << "Vehicle Default constructor" << std::endl; };
	Vehicle ( std::string name, 
		      short capacity )
		:name_(name), capacity_(capacity) 
	{ std::cout << "Vehicle constructor" << std::endl; }

	const std::string &getName (void) { return name_; };
	short getCapacity (void) { return capacity_; };
};

// Simple Inheritance Class
class Land: virtual public Vehicle {
private:
	short wheels_;

	Land();
public:
	Land ( std::string name, 
		   short capacity,
		   short wheels )
		: Vehicle(name, capacity), 
		  wheels_(wheels) 
	{ std::cout << "Land constructor" << std::endl; }

	short getNumWheels (void) { return wheels_; }
};

// Simple Inheritance Class
class Air: virtual public Vehicle {
	short engines_;

	Air();
public:
	Air ( std::string name,
		  short capacity,
		  short engines )
		: Vehicle(name, capacity), 
		  engines_(engines)
	{ std::cout << "Air constructor" << std::endl; }

	short getNumEngines(void) { return engines_; }
};

// Simple Inheritance Class - Second Order
class Car: public Land {
	short doors_;
	Car ();
public:
	Car ( std::string name, 
		  short capacity, 
		  short wheels, 
		  short doors )
		: Vehicle(name, capacity), 
		  Land(name, capacity, wheels), 
		  doors_(doors) 
	{ std::cout << "Car constructor" << std::endl; }	

	short getNumDoors (void) { return doors_; }
};

// Multiple Inheritance - Second Order - Common Base
class Airplane: public Land, public Air {
	short pilots_;

	Airplane();
public:
	Airplane ( std::string name, 
		       short capacity, 
			   short wheels, 
			   short engines,
			   short pilots)
		: Vehicle(name, capacity), 
		  Land(name, capacity, wheels), 
		  Air(name, capacity, engines), 
		  pilots_(pilots)
	{ std::cout << "Airplane constructor" << std::endl; }
};

#endif
