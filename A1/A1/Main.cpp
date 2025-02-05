// Includes the Array.h header file for function declarations.
#include "Array.h"
#include "Point.h"


// Includes the input/output stream library for IO operations.
#include <iostream>


/*
 * The main function where the program starts executing.
 */
int main()
{
	Point p;

	// Variable to store the size of the array entered by the user.
	int size;
	// Prompt the user to enter the array size.
	std::cout << "Enter the size of the array: ";
	// Read the user input for the size of the array.
	std::cin >> size;

	// Notify the user that the array is about to be created.
	std::cout << "Creating the array...\n\n";
	// Call the createArray function to allocate memory for the array.
	int* a = createArray(size);

	// Notify the user that the array is about to be initialized.
	std::cout << "Initializing the array...\n\n";
	initializeArray(a, size);

	// Notify the user that the elements in the array are about to be displayed.
	std::cout << "Printing the elements in the array...\n";
	// Call the printArray function to print the contents of the array.
	printArray(a, size);

	// Notify the user that the array is about to be deleted.
	std::cout << "Deleting the array...\n\n";
	// Call the deleteArray function to deallocate the memory of the array.
	deleteArray(a);

	//Reprint now deleted array
	std::cout << "Reprint the array...\n\n";
	printArray(a, size);

	// variables to store direction and distance for Part 2: Points
	int d;
	char axis;

	// Prompt the user to enter distance
	std::cout << "Enter the distance";
	// Read the user input for distance
	std::cin >> d;

	//checking for if user enters something else than number 
	if (!d)
	{
		std::cout << "Error Code - 1";
		exit(0);
	}
	// Prompt the user to enter axis
	std::cout << "Enter which axis (x or y or z) ";
	// Read the user input for axis
	std::cin >> axis;
	//Calling translation function      
	p.translate(d, axis);











	// Return 0 to indicate the successful completion of the program.
	return 0;
}