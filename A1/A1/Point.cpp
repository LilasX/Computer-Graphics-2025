// Includes the Point.h header file for function declarations.
#include "Point.h"

// Includes the input/output stream library for IO operations.
#include <iostream>

void Point::translate(int d, char axis)
{
	
	switch (axis)
	{
	case 'x':
		x = x + d;
		std::cout << "New x/y/z Coordinates: " << x << "/" << y << "/" << z;
		break;

	case 'y':
		y = y + d;
		std::cout << "New x/y/z Coordinates: " << x << "/" << y << "/" << z;
		break;

	case 'z':
		z = z + d;
		std::cout << "New x/y/z Coordinates: " << x << "/" << y << "/" << z;
		break;

	default:
		std::cout << "Error Code -1";

	}

	
};
