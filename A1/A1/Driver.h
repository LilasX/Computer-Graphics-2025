// Start of the header guard to prevent multiple inclusions of this file.
#ifndef DRIVER_H
#define DRIVER_H

// Includes the Triangle.h header file for function declarations.
#include "Triangle.h"

// Includes the C++ Standard Library's string header, which provides the std::string class.
#include <string>

/*
 * Declaration of the Driver class that will manage the user interface and triangle operations.
 */
class Driver
{
private:
	// Pointer to a Triangle object, used to store the current triangle being worked on.
	Triangle* triangle;

public:
	/*
	 * Default constructor declaration for the Driver class, initializes triangle to nullptr.
	 */
	Driver();

	/*
	 * Function to create a triangle by prompting the user for 3 points' coordinates.
	 */
	void createTriangle();

	/*
	 * Function to translate the triangle along a specified axis by a certain distance.
	 */
	void translateTriangle();

	/*
	 * Function to display the current triangle's coordinates.
	 */
	void displayTriangle();

	/*
	 * Function to calculate the area of the current triangle.
	 */
	void calculateTriangleArea();

	/*
	 * Helper function to validate if a given string input is a valid integer.
	 *
	 * @param stringInput The input string to validate.
	 * @return True if the input is a valid integer, false otherwise.
	 */
	bool isValidInputInt(const std::string& stringInput);

	/*
	 * Function to display the main menu and handle user input for triangle operations.
	 */
	void menu();
};

// End of the header guard to prevent multiple inclusions of this file.
#endif