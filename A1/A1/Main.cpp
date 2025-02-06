// Includes the Array.h header file for function declarations.
#include "Array.h"
// Includes the Driver.h header file for the driver class and menu-related functions.
#include "Driver.h"


// Includes the input/output stream library for console IO operations.
#include <iostream>
// Includes the string library to work with strings.
#include <string>
// Includes the C standard library to work with system-specific functions.
#include <cstdlib>


 // The main function where the program starts executing.
int main()
{
	// Create an instance of the Driver class to handle the user menu and triangle operations.
	Driver driver;
	// Declare a variable to capture the user's choice for creating another array.
	char choice;

	// Start an infinite loop to allow the user to create multiple arrays until they choose to exit.
	do
	{
		// Print the title for the Dynamic Array section.
		std::cout << "Dynamic Array\n\n";

		// Declare an integer to store the size of the array.
		int size;
		// Declare a string to capture user input.
		std::string input;

		// Declare a boolean flag to validate the array size.
		bool isValidSize = false;
		// Declare a boolean flag to validate the user's choice for creating another array.
		bool isValidChoice = false;

		// Loop until a valid array size is entered by the user.
		while (!isValidSize)
		{
			// Prompt the user to enter the size of the array.
			std::cout << "Enter the size of the array: ";
			// Read the user input for the size of the array.
			std::getline(std::cin, input);

			// Check if the input is a valid integer.
			if (driver.isValidInputInt(input))
			{
				// Convert the string input to an integer and store it in the size variable.
				size = std::stoi(input);
				// If the size is a positive integer, proceed to validate the size.
				if (size <= 0)
				{
					// Notify the user that the array size is invalid if it’s less than or equal to zero.
					std::cout << "Invalid array size! Please enter a positive integer!\n\n";
				}
				// Set isValidSize to true to exit the loop since the size is valid.
				else
				{
					isValidSize = true;
				}
			}
			// If the input is not a valid integer, prompt the user again for a valid input.
			else
			{
				std::cout << "Invalid Input! Please enter a valid integer!\n\n";
			}
		}

		// Notify the user that the array is about to be created.
		std::cout << "\nCreating the array...\n\n";
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

		// Loop to validate the user's choice for creating another array.
		while (!isValidChoice)
		{
			// Ask the user if they want to create another array.
			std::cout << "Create another array?\n";
			// Prompt the user to enter 'y' for yes or 'n' for no.
			std::cout << "Please enter y for yes or enter n for no: ";
			// Read the user's input.
			std::getline(std::cin, input);

			// Check if the input is a single alphabetic character.
			if (input.length() == 1 && std::isalpha(input[0]))
			{
				// Store the user's input in the 'choice' variable.
				choice = input[0];
				// Check if the input is either 'y', 'Y', 'n', or 'N'.
				if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
				{
					// Set isValidChoice to true to exit the loop and proceed to the next step.
					isValidChoice = true;
					std::cout << "\n\n";			
				}
				// If the input is invalid, prompt the user again for a valid choice.
				else
				{
					std::cout << "Invalid choice! Please enter y (yes) or n (no)!\n\n";
				}
			}
			// If the input is not valid, prompt the user again for a valid choice.
			else
			{
				std::cout << "Invalid Input! Please enter a valid integer!\n\n";
			}
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

		// If the user chooses 'n' or 'N', print a message and exit the loop.
		if (choice == 'n' || choice == 'N')
		{
			std::cout << "\nEnd of Dynamic Array Manipulation...\n\n";
		}
	} 
	// Continue the loop if the user chooses to create another array ('y' or 'Y').
	while (choice == 'y' || choice == 'Y');

	// After finishing with arrays, call the Driver class's menu function to start the menu-driven program.
	driver.menu();

	// Return 0 to indicate the successful completion of the program.
	return 0;
}