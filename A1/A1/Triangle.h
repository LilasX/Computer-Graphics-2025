
// Start of the header guard to prevent multiple inclusions of this file.
#ifndef TRIANGLE_H
#define TRIANGLE_H

// Includes the Point.h header file to use the Point class for vertices.
#include "Point.h"

/*
 * Defines a Triangle class to represent a triangle using 3 Point vertices.
 */
class Triangle
{
private:
	/*
	 * Pointer to the first vertex of the triangle.
	 * It will point to a dynamically allocated Point object.
	 */
	Point* vertex_1;
	/*
	 * Pointer to the second vertex of the triangle.
	 * It will point to a dynamically allocated Point object.
	 */
	Point* vertex_2;
	/*
	* Pointer to the third vertex of the triangle.
	* It will point to a dynamically allocated Point object.
	*/
	Point* vertex_3;
	
public:
	/*
	 * Default constructor for the Triangle class.
	 * Initializes the vertex pointers to nullptr.
	 */
	Triangle();

	/*
	 * Constructor for the Triangle class that initializes the 3 vertices.
	 *
	 * @param a Pointer to the first vertex (Point).
	 * @param b Pointer to the second vertex (Point).
	 * @param c Pointer to the third vertex (Point).
	 */
	Triangle(Point *a, Point *b, Point *c);

	/*
	 * Destructor for the Triangle class. 
	 * It deletes the dynamically allocated vertices.
	 */
	~Triangle();

	/*
	 * Translates the entire triangle by a specified distance along a given axis.
	 *
	 * @param d The distance to translate the triangle along the axis.
	 * @param axis The axis along which to translate ('x', 'y', or 'z').
	 */
	void translate(int d, char axis);

	/*
	 * Calculates the area of the triangle using the vertices' coordinates.
	 *
	 * @return The area of the triangle.
	 */
	double calcArea();
	
	/*
	 * Displays the coordinates of the three vertices forming the triangle.
	 */
	void displayTriangle() const;
};

// End of the header guard to prevent multiple inclusions of this file.
#endif