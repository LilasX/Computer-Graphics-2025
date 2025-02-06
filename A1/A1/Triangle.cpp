// Includes the input/output stream library for IO operations.
#include <iostream>
// Includes the Triangle.h header file for function declarations.
#include "Triangle.h"
// Includes the Point.h header file for function declarations.
#include "Point.h"


//takes memory location of 3 point classes then passes them to the 3 vertexes of one triangle
Triangle::Triangle(Point* a, Point* b, Point* c)
{	
// Assign each vertex pointer the memory location of their respective points that was passed by the function
	vertex1->x = a->x;
	vertex1->y = a->y;
	vertex1->z = a->z;

	vertex2->x = b->x;
	vertex2->y = b->y;
	vertex2->z = b->z;

	vertex3->x = c->x;
	vertex3->y = c->y;
	vertex3->z = c->z;
}

//translation function for triangle. super simple 
void Triangle::translate(int d, char axis)
{
	switch (axis)
	{
	case 'x':
		vertex1->x = (vertex1->x) + d;
		vertex2->x = (vertex2->x) + d;
		vertex3->x = (vertex3->x) + d;

		break;

	case 'y':
		vertex1->y = (vertex1->y) + d;
		vertex2->y = (vertex2->y) + d;
		vertex3->y = (vertex3->y) + d;

		break;

	case 'z':
		vertex1->z = (vertex1->z) + d;
		vertex2->z = (vertex2->z) + d;
		vertex3->z = (vertex3->z) + d;

		break;

	default:
		std::cout << "Error Code -1";
	}
}

//chatgpt (delete this comment later) formula for area of 2d triangle in a 3d plane 
double Triangle::area()
{
	
	// Compute the cross product of vectors AB and AC
	double Nx = (vertex2->y - vertex1->y) * (vertex3->z - vertex1->z) - (vertex2->z - vertex1->z) * (vertex3->y - vertex1->y);
	double Ny = (vertex2->z - vertex1->z) * (vertex3->x - vertex1->x) - (vertex2->x - vertex1->x) * (vertex3->z - vertex1->z);
	double Nz = (vertex2->x - vertex1->x) * (vertex3->y - vertex1->y) - (vertex2->y - vertex1->y) * (vertex3->x - vertex1->x);

	// Compute the magnitude of the cross product vector
	double crossProductMagnitude = std::sqrt(Nx * Nx + Ny * Ny + Nz * Nz);

	// Area of the triangle
	return 0.5 * crossProductMagnitude;
}

// prints the xyz of all 3 vertices forming the triangle
void Triangle::print()
{
	std::cout << vertex1->x;
	std::cout << vertex1->y;
	std::cout << vertex1->z;

	std::cout << vertex2->x;
	std::cout << vertex2->y;
	std::cout << vertex2->z;

	std::cout << vertex3->x;
	std::cout << vertex3->y;
	std::cout << vertex3->z;
}