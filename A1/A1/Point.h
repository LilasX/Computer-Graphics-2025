// Start of the header guard to prevent multiple inclusions of this file.
#ifndef POINT_H
#define POINT_H

// Includes the input/output stream library for IO operations.
#include <iostream>

class Point
{
private:
    int x=0, y=0, z=0;
public:
    //  function declaration for translation of point function
    void translate(int d, char axis);
};

#endif