
// Start of the header guard to prevent multiple inclusions of this file.
#ifndef TRIANGLE_H
#define TRIANGLE_H

// Includes the input/output stream library for IO operations.
#include <iostream>
#include "Point.h"

class Triangle
{
private:
	//declare the 3 vertex pointers that will point to a Point Memory Location and initializes their size
	Point *vertex1 = new Point(), *vertex2 = new Point(), *vertex3 = new Point();
	
public:
	//declare the constructor called for every triangle
	Triangle(Point *a, Point *b, Point *c);
	//declare the translation function
	void translate(int d, char axis);
	//declare the area of triangle function
	double area();
	
	void print();

};

#endif