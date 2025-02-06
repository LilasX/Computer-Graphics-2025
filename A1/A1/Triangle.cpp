// Includes the Triangle.h header file for function declarations.
#include "Triangle.h"
// Includes the Point.h header file for function declarations.
#include "Point.h"

// Includes the input/output stream library for IO operations.
#include <iostream>
// Includes cmath for the sqrt function used in area calculation.
#include <cmath>

/*
 * Default constructor for the Triangle class.
 * Initializes all vertex pointers to nullptr, meaning no vertices are assigned.
 */
Triangle::Triangle() : vertex_1(nullptr), vertex_2(nullptr), vertex_3(nullptr)
{
	// Constructor body is empty since initialization is done in the initialization list.
}

/*
 * Constructor for the Triangle class that initializes the 3 vertices with given Point pointers.
 *
 * @param a Pointer to the first vertex (Point).
 * @param b Pointer to the second vertex (Point).
 * @param c Pointer to the third vertex (Point).
 */
Triangle::Triangle(Point* a, Point* b, Point* c)
{	
	// The first vertex of the triangle is assigned the memory address of point 'a'.
	vertex_1 = a;
	// The second vertex of the triangle is assigned the memory address of point 'b'.
	vertex_2 = b;
	// The third vertex of the triangle is assigned the memory address of point 'c'.
	vertex_3 = c;
}

/*
 * Destructor for the Triangle class.
 * Deletes the dynamically allocated memory for the three vertex points.
 */
Triangle::~Triangle()
{
	// Checks if the first vertex is not nullptr, then deletes the allocated memory.
	if (vertex_1 != nullptr)
	{
		delete vertex_1;
	}

	// Checks if the second vertex is not nullptr, then deletes the allocated memory.
	if (vertex_2 != nullptr)
	{
		delete vertex_2;
	}

	// Checks if the third vertex is not nullptr, then deletes the allocated memory.
	if (vertex_3 != nullptr)
	{
		delete vertex_3;
	}
}

/*
 * Translates the entire triangle by a specified distance along a given axis.
 *
 * @param d The distance to translate the triangle along the axis.
 * @param axis The axis along which to translate ('x', 'y', or 'z').
 */
void Triangle::translate(int d, char axis)
{
	// If the first vertex exists, translate it along the given axis.
	if (vertex_1 != nullptr)
	{
		vertex_1->translate(d, axis);
	}

	// If the second vertex exists, translate it along the given axis.
	if (vertex_2 != nullptr)
	{
		vertex_2->translate(d, axis);
	}

	// If the third vertex exists, translate it along the given axis.
	if (vertex_3 != nullptr)
	{
		vertex_3->translate(d, axis);
	}
}

/*
 * Calculates the area of the triangle using the vertices' coordinates.
 * Uses the cross product of two vectors formed by the vertices to compute the area.
 *
 * @return The area of the triangle. Returns 0.0 if any vertex is not assigned.
 */
double Triangle::calcArea()
{
	// If any of the vertices is null, return area as 0.0.
	if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr)
	{
		return 0.0;
	}

	// Compute Vector AB based on the coordinates of the first and second vertices.
	int abX = vertex_2->getCoordinateX() - vertex_1->getCoordinateX();
	int abY = vertex_2->getCoordinateY() - vertex_1->getCoordinateY();
	int abZ = vertex_2->getCoordinateZ() - vertex_1->getCoordinateZ();

	// Compute Vector AC based on the coordinates of the first and third vertices.
	int acX = vertex_3->getCoordinateX() - vertex_1->getCoordinateX();
	int acY = vertex_3->getCoordinateY() - vertex_1->getCoordinateY();
	int acZ = vertex_3->getCoordinateZ() - vertex_1->getCoordinateZ();

	// Compute the cross product of vectors AB and AC.
	int vX = abY * acZ - acY * abZ;
	int vY = -(abX * acZ - acX * abZ);
	int vZ = abX * acY - acX * abY;

	// Compute the magnitude of the cross product vector.
	double crossProductMagnitude = sqrt(vX * vX + vY * vY + vZ * vZ);

	// The area of the triangle is half the magnitude of the cross product.
	return 0.5 * crossProductMagnitude;
}

/*
 * Displays the coordinates of the three vertices forming the triangle.
 */
void Triangle::displayTriangle() const
{
	// Prints the header for the triangle's coordinates.
	std::cout << "- Triangle's Coordinates - \n";

	// Displays the coordinates of the first vertex.
	std::cout << "First Vertex Coordinate: ";
	vertex_1->displayPoint();

	// Displays the coordinates of the second vertex.
	std::cout << "Second Vertex Coordinate: ";
	vertex_2->displayPoint();

	// Displays the coordinates of the third vertex.
	std::cout << "Third Vertex Coordinate: ";
	vertex_3->displayPoint();

	// Prints a newline after displaying all the coordinates.
	std::cout << "\n";
}