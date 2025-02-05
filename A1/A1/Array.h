// Start of the header guard to prevent multiple inclusions of this file.
#ifndef ARRAY_H
#define ARRAY_H

// Includes the input/output stream library for IO operations.
#include <iostream>

/*
 * Creates and dynamically allocates an integer array of a given size.
 *
 * @param size The size of the array to be created.
 * @return A pointer to the created array of integers.
 */
int* createArray(int size);

/*
 * Initializes an integer array of a given size with sequential integers.
 *
 * @param array The pointer to the array to be initialized.
 * @param size The size of the array to be initialized.
 */
void initializeArray(int* array, int size);

/*
 * Prints the elements of an integer array.
 *
 * @param array The pointer to the array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int* array, int size);

/*
 * Deletes an array that was dynamically allocated.
 *
 * @param array The pointer to the array to be deleted.
 */
void deleteArray(int* array);

// End of the header guard.
#endif