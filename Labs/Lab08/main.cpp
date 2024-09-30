#include <cstdlib>

#include "Shape.h"
#include "TemplateFunction.h"
#include "TemplateClass.h"

// Forward Declarations
void template_function_demo();
void template_class_demo();

/*
 * Function Pointer Demo
 *
 * Usage :: "type (*name)(arguments)"
 *    ex :: int (*f) (int, float);	// A pointer to a function returning an int value, taking two arguments. An int and a float
 *          void (*f) (int *);		// A pointer to a function that does not return a value, taking as argument a pointer to int (int *)
 */
void (*function)();

int main(int argc, char *argv) {
	function = template_function_demo;
	//function = template_class_demo;

	//this is the same as calling the template_demo() or the polymorphism_demo() example
	function();	// or (*function)();

	system ("pause");
	return 0;
}

void template_function_demo() {
	// TODO call compare function using the following types as arguments
	// Int Arguments
	compare(4, 5);
	// Float arguments
	compare(.4, .5);

	// -------------------------------- //
	// Dynamically allocate memory for a Shape array that holds two shapes
	Shape **shape_array = new Shape*[2];

	//put some shapes in the array
	shape_array[0] = new Circle (Point2D(0,0), 5);
	shape_array[0]->setName("Circle 1");

	shape_array[1] = new Quad (Point2D(0,0), 15);
	shape_array[1]->setName("Quad 1");

	//draw all the shapes in the array
	for (int i=0; i<2; i++)
		shape_array[i]->draw();

	cout << "-----------------" << endl;

	//print the area of some shapes
	cout << "Area of " << *shape_array[0] << " : " << shape_array[0]->getArea() << endl;
	cout << "Area of " << *shape_array[1] << " : " << shape_array[1]->getArea() << endl;

	// TODO:: Make the necessary modifications to the Shape Class so that it can be used
	//        with the compare function
	// Using Shape Object arguments
	compare((*shape_array[0]), (*shape_array[1]));

	// Delete allocated shapes
	delete shape_array[0];
	delete shape_array[1];
	// Delete memory of shape array
	delete []shape_array;
}

void template_class_demo() {
	// Using the templated class Vector
	Vector<float, 4> test;
	test[0]=2.2f;
	test[2]=3.2f;
	test.print();

	// TODO: Make the necessary modification to the Vector class so that it will not crash
	//       with the following lines
	test[-1]=2.2f;
	test[10]=0.f;
	test.print();

	// TODO: Implement the getMax() function correctly
	cout << "The maximum is: " << test.getMax() << endl;
}