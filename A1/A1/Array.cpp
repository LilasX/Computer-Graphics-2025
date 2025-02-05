// Includes the Array.h header file for function declarations.
#include "Array.h"

// Includes the input/output stream library for IO operations.
#include <iostream>

/*
 * Creates and dynamically allocates an integer array of a given size.
 *
 * @param size The size of the array to be created.
 * @return A pointer to the created array of integers.
 */
int* createArray(int size)
{
    // Allocates memory dynamically for the array and returns a pointer to it.
    return new int[size];
}

/*
 * Initializes an integer array of a given size with sequential integers.
 *
 * @param array The pointer to the array to be initialized.
 * @param size The size of the array to be initialized.
 */
void initializeArray(int* array, int size)
{
    // Loop through the array.
    for(int i = 0; i < size; i++)
    {
        // Initialize each element with the current index value.
        array[i] = i;
    }
}

/*
 * Prints the elements of an integer array.
 *
 * @param array The pointer to the array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int* array, int size)
{
    // Print the opening bracket.
    std::cout << "[ ";
    // Loop through each element of the array.
    for(int i = 0; i < size; i++)
    {
        // Print the current element of the array.
        std::cout << array[i] << " ";
    }
    // Print the closing bracket and move to a new line.
    std::cout<< "]\n\n";
}

/*
 * Deletes an array that was dynamically allocated.
 *
 * @param array The pointer to the array to be deleted.
 */
void deleteArray(int* array)
{
    // Deallocates the memory for the array to avoid memory leaks.
    delete[] array;
}

/*
 * The main function where the program starts executing.
 */
int main()
{
    // Variable to store the size of the array entered by the user.
    int size;
    // Prompt the user to enter the array size.
    std::cout << "Enter the size of the array: ";
    // Read the user input for the size of the array.
    std::cin >> size;

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

    // Return 0 to indicate the successful completion of the program.
    return 0;
}