// Includes the Point.h header file for function declarations.
#include "Point.h"

// Includes the input/output stream library for IO operations.
#include <iostream>

/*
 * Constructor for the Point class. 
 * Initializes the point's coordinates.
 *
 * @param xParameter The x-coordinate to initialize.
 * @param yParameter The y-coordinate to initialize.
 * @param zParameter The z-coordinate to initialize.
 */
Point::Point(int xParameter, int yParameter, int zParameter) : x(xParameter), y(yParameter), z(zParameter)
{
	// The constructor body is empty as the initialization is done in the initialization list.
}

/*
 * Destructor for the Point class.
 */
Point::~Point()
{
	// There is no dynamic memory to free, so the destructor remains empty.
}

/*
 * Getter for the x-coordinate of the point.
 *
 * @return The x-coordinate.
 */
int Point::getCoordinateX() const
{
	return x;
}

/*
 * Getter for the y-coordinate of the point.
 *
 * @return The y-coordinate.
 */
int Point::getCoordinateY() const
{
	return y;
}

/*
 * Getter for the z-coordinate of the point.
 *
 * @return The z-coordinate.
 */
int Point::getCoordinateZ() const
{
	return z;
}

/*
 * Translates the point along a specified axis by a given distance.
 *
 * @param d The distance to translate along the axis.
 * @param axis The axis along which to translate ('x', 'y', or 'z').
 * @return 0 if the translation is successful, -1 if the axis is invalid.
 */
int Point::translate(int d, char axis)
{
	// Switch statement to check the axis and translate accordingly.
	switch (axis)
	{
	// If the axis is 'x', adjust the x-coordinate.
	case 'x':
		x = x + d;
		return 0;

	// If the axis is 'y', adjust the y-coordinate.
	case 'y':
		y = y + d;
		return 0;

	// If the axis is 'z', adjust the z-coordinate.
	case 'z':
		z = z + d;
		return 0;

	// If the axis is invalid, return -1 indicating an error.
	default:
		return -1;
	}
};

/*
 * Displays the point's coordinates in the format (x, y, z).
 */
void Point::displayPoint() const
{
	std::cout << "(" << getCoordinateX() << ", " << getCoordinateY() << ", " << getCoordinateZ() << ")\n";
}
