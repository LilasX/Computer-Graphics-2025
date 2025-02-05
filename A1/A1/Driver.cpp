#include <iostream>
#include "Point.h"
#include "Triangle.h"


// First asks the user to input xyz coordinates for 3 points, then passes their memory location to the triangle constructor and finally returns a triangle (wtf)
// The reason triangles are made in such a convoluted way is because the assignemeents requires that the non-default constructor has 3 points as arugments / parameters 
Triangle createTriangle()
{
	Point* a = new Point();
	Point* b = new Point();
	Point* c = new Point();

	std::cout << "Enter x coord of first point";
	std::cin >> a->x;
	std::cout << "Enter y coord of first point";
	std::cin >> a->y;
	std::cout << "Enter z coord of first point";
	std::cin >> a->z;

	std::cout << "Enter x coord of second point";
	std::cin >> b->x;
	std::cout << "Enter y coord of second point";
	std::cin >> b->y;
	std::cout << "Enter z coord of second point";
	std::cin >> b->z;

	std::cout << "Enter x coord of third point";
	std::cin >> c->x;
	std::cout << "Enter y coord of third point";
	std::cin >> c->y;
	std::cout << "Enter z coord of third point";
	std::cin >> c->z;

	Triangle tri(a, b, c);

	return tri;

}