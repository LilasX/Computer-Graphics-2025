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

