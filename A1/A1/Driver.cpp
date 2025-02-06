// Includes the Driver.h header file for function declarations.
#include "Driver.h"
// Includes the Triangle.h header file for function declarations.
#include "Triangle.h"
// Includes the Point.h header file for function declarations.
#include "Point.h"

// Includes the input/output stream library for performing input/output operations in the console.
#include <iostream>
// Includes the string library to work with string variables for user input.
#include <string>
// Includes the stringstream library to convert string inputs into integer values.
#include <sstream>
// Includes the standard library for system commands such as clearing the screen.
#include <cstdlib>
// Includes the cctype library for character manipulation functions like 'tolower'.
#include <cctype>

/*
 * Default constructor for the Driver class.
 * Initializes the triangle pointer to nullptr, meaning no triangle is created when the Driver object is first instantiated.
 */
Driver::Driver()
{
	// Initialize triangle pointer to nullptr, indicating no triangle object exists yet.
	triangle = nullptr;
}

/*
 * Creates a triangle by asking the user to input the coordinates of three points.
 * The function dynamically allocates memory for the three points and constructs a Triangle object using these points.
 * It also handles invalid input properly and ensures proper integer inputs for the coordinates.
 */
void Driver::createTriangle()
{
// Clears the console screen for Windows operating systems.
#ifdef _WIN32
	system("cls");
// Clears the console screen for Unix-based or macOS systems.
#elif __unix__ || __APPLE__
	system("clear");
// If the OS doesn't support clear, show an error.
#else
	std::cerr << "Clear console command not supported on this OS.\n";
#endif

	// Declare pointers to three Point objects, initialized to nullptr.
	Point* a = nullptr;
	Point* b = nullptr;
	Point* c = nullptr;

	// Declare a string variable to hold user input.
	std::string input;

	// Declare integer variables to store the x, y, and z coordinates.
	int coordinateX;
	int coordinateY;
	int coordinateZ;

	// Input and validation for the first point (x coordinate).
	std::cout << "Enter the x coordinate of the first point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateX = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the first point (y coordinate).
	std::cout << "Enter the y coordinate of the first point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateY = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the first point (z coordinate).
	std::cout << "Enter the z coordinate of the first point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateZ = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Dynamically allocate memory for Point 'a' and initialize it with the user input.
	a = new Point(coordinateX, coordinateY, coordinateZ);

	// Input and validation for the second point (x coordinate).
	std::cout << "\nEnter the x coordinate of the second point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateX = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the second point (y coordinate).
	std::cout << "Enter the y coordinate of the second point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateY = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the second point (z coordinate).
	std::cout << "Enter the z coordinate of the second point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateZ = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Dynamically allocate memory for Point 'b' and initialize it with the user input.
	b = new Point(coordinateX, coordinateY, coordinateZ);

	// Input and validation for the third point (x coordinate).
	std::cout << "\nEnter the x coordinate of the third point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateX = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the third point (y coordinate).
	std::cout << "Enter the y coordinate of the third point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateY = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the third point (z coordinate).
	std::cout << "Enter the z coordinate of the third point: ";
	// Read input from the user.
	std::getline(std::cin, input);
	// Validate that the input is a valid integer.
	if (isValidInputInt(input))
	{
		// Convert the input string to an integer.
		coordinateZ = std::stoi(input);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Dynamically allocate memory for Point 'c' and initialize it with the user input.
	c = new Point(coordinateX, coordinateY, coordinateZ);

	// Construct the triangle using the three points 'a', 'b', and 'c'.
	triangle = new Triangle(a, b, c);

	// Confirm that the triangle has been successfully created.
	std::cout << "\nTriangle created!\n\n";
}

/*
 * This function translates the existing triangle along a specified axis (X, Y, or Z) by a given distance.
 * It ensures that the triangle has been created before performing the translation.
 */
void Driver::translateTriangle()
{
	// Exit the function if no triangle has been created.
	if (triangle == nullptr)
	{
		std::cout << "No Triangle has been created previously. Please create a triangle before using this option.\n\n";
		return;
	}

// Clears the console screen for Windows operating systems.
#ifdef _WIN32
	system("cls");
// Clears the console screen for Unix-based or macOS systems.
#elif __unix__ || __APPLE__
	system("clear");
// If the OS doesn't support clear, show an error.
#else
	std::cerr << "Clear console command not supported on this OS.\n";
#endif

	// Declare a variable to store the translation distance.
	int distance;
	// Declare a variable to store the axis for translation.
	char axis;
	// Declare a string variable for user input of the translation distance.
	std::string inputD;
	// Declare a string variable for user input of the translation axis.
	std::string inputA;

	// Input and validation for the translation distance.
	std::cout << "Enter the distance to translate the triangle: ";
	// Read input from the user.
	std::getline(std::cin, inputD);
	// Validate that the distance input is a valid integer.
	if (isValidInputInt(inputD))
	{
		// Convert the string input to an integer.
		distance = std::stoi(inputD);
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid integer next time!\n\n";
		return;
	}

	// Input and validation for the translation axis.
	std::cout << "Enter the axis (x or y or z) to translate the triangle to: ";
	// Read input from the user.
	std::getline(std::cin, inputA);
	// Check if the input is a single alphabetical character.
	if (inputA.length() == 1 && std::isalpha(inputA[0]))
	{
		// Convert the character to lowercase.
		axis = std::tolower(inputA[0]);
		// Check if the axis is valid (x, y, or z).
		if (!(axis == 'x' || axis == 'y' || axis == 'z'))
		{
			// Exit the function if the axis is invalid.
			std::cout << "Invalid Input! Please enter a valid axis next time!\n\n";
			return;
		}
	}
	// Exit the function if the input is invalid.
	else
	{
		std::cout << "Invalid Input! Please enter a valid axis next time!\n\n";
		return;
	}

	// Perform the translation of the triangle using the input values.
	triangle->translate(distance, axis);

	// Confirm that the triangle has been successfully translated.
	std::cout << "\nTriangle translated!\n\n";
}

/*
 * This function displays the current coordinates of the triangle's three vertices.
 * It ensures that the triangle has been created before displaying the coordinates.
 */
void Driver::displayTriangle()
{
	// Exit the function if no triangle has been created.
	if (triangle == nullptr)
	{
		std::cout << "No Triangle has been created previously. Please create a triangle before using this option.\n\n";
		return;
	}

// Clears the console screen for Windows operating systems.
#ifdef _WIN32
	system("cls");
// Clears the console screen for Unix-based or macOS systems.
#elif __unix__ || __APPLE__
	system("clear");
// If the OS doesn't support clear, show an error.
#else
	std::cerr << "Clear console command not supported on this OS.\n";
#endif

	// Call the display method of the Triangle class to print the triangle's coordinates.
	triangle->displayTriangle();
}

/*
 * This function calculates the area of the triangle based on its three vertices.
 * It ensures that the triangle has been created before performing the area calculation.
 */
void Driver::calculateTriangleArea()
{
	// Exit the function if no triangle has been created.
	if (triangle == nullptr)
	{
		std::cout << "No Triangle has been created previously. Please create a triangle before using this option.\n\n";
		return;
	}

// Clears the console screen for Windows operating systems.
#ifdef _WIN32
	system("cls");
// Clears the console screen for Unix-based or macOS systems.
#elif __unix__ || __APPLE__
	system("clear");
// If the OS doesn't support clear, show an error.
#else
	std::cerr << "Clear console command not supported on this OS.\n";
#endif
	
	// Call the calcArea method of the Triangle class to calculate and display the area.
	std::cout << "Triangle Area: " << triangle->calcArea() << "\n\n";
}

/*
 * This helper function validates if the input string can be converted to a valid integer.
 * It returns true if the string is a valid integer, otherwise returns false.
 */
bool Driver::isValidInputInt(const std::string& stringInput)
{
	// Return false if the input string is empty.
	if (stringInput.empty())
	{
		return false;
	}

	// Create a stringstream to process the string input.
	std::stringstream ss(stringInput);
	// Declare an integer to store the converted value.
	int inputInt;
	// Try converting the string to an integer.
	ss >> inputInt;

	// Checks if the entire string has been successfully processed and converted to an integer.
	// `ss.eof()` checks if the end of the input string has been reached, meaning the entire string was read.
	// `!ss.fail()` ensures that the string was successfully converted into an integer without errors.
	// If both conditions are true, it means the input string represents a valid integer. Otherwise, it is not.
	return ss.eof() && !ss.fail();
}

/*
 * This function displays a menu with various options for the user to interact with the program.
 * It allows the user to create a triangle, translate it, display its coordinates, calculate its area, or exit.
 */
void Driver::menu()
{
	// Declare an integer to store the user's menu choice.
	int option;
	// Declare a string to capture user input.
	std::string input;

	// Start an infinite loop to repeatedly show the menu until the user exits.
	while (true)
	{
		// Display the menu options to the user.
		std::cout << "--- Triangle Menu Options ---\n\n";
		std::cout << "1- Create a new Triangle\n";
		std::cout << "2- Translate Triangle\n";
		std::cout << "3- Display Triangle's Coordinates\n";
		std::cout << "4- Calculate Triangle's Area\n";
		std::cout << "5- Exit\n\n";
		std::cout << "Select an option: ";

		// Read the user input.
		std::getline(std::cin, input);
		// Validate that the input is a valid integer.
		if (isValidInputInt(input))
		{
			// Convert the string input to an integer.
			option = std::stoi(input);
		}
		// If the input is invalid, prompt the user again.
		else
		{
			std::cout << "Invalid Input! Please enter a valid integer!\n\n";
			// Skip the rest of the loop and ask the user for input again.
			continue;
		}
		std::cout << "\n\n";

		// Perform the action based on the user's menu selection using a switch statement.
		switch (option)
		{
		case 1:
			// Call the createTriangle function to initialize a new triangle.
			createTriangle();
			break;
		case 2:
			// Call the translateTriangle function to move the triangle.
			translateTriangle();
			break;
		case 3:
			// Call the displayTriangle function to show the triangle's coordinates.
			displayTriangle();
			break;
		case 4:
			// Call the calculateTriangleArea function to compute the area.
			calculateTriangleArea();
			break;
		case 5:
			// Delete the dynamically allocated memory for the triangle object (if created).
			delete triangle;
			// Print an exit message to notify the user.
			std::cout << "Exiting...\n";
			// Exit the menu function
			return;
		default:
			// Print an error message for invalid options and prompt the user to try again.
			std::cout << "Invalid option! Please try again!\n\n";
		}
	}
}