// Start of the header guard to prevent multiple inclusions of this file.
#ifndef POINT_H
#define POINT_H

/*
 * Defines a Point class to represent a 3D point in space with x, y, and z coordinates.
 */
class Point
{
private:
    // Integer member variable x initialized to 0, representing the x-coordinate.
    int x = 0;
    // Integer member variable y initialized to 0, representing the y-coordinate.
    int y = 0;
    // Integer member variable z initialized to 0, representing the z-coordinate.
    int z = 0;

public:  
    /*
     * Constructor that initializes the x, y, and z coordinates of the point.
     *
     * @param xParameter The x-coordinate of the point.
     * @param yParameter The y-coordinate of the point.
     * @param zParameter The z-coordinate of the point.
     */
    Point(int xParameter, int yParameter, int zParameter);

    /*
     * Destructor for the Point class.
     */
    ~Point();

    /*
     * Getter for the x-coordinate of the point.
     *
     * @return The x-coordinate.
     */
    int getCoordinateX() const;
    /*
     * Getter for the y-coordinate of the point.
     *
     * @return The y-coordinate.
     */
    int getCoordinateY() const;
    /*
     * Getter for the z-coordinate of the point.
     *
     * @return The z-coordinate.
     */
    int getCoordinateZ() const;

    /*
     * Translates the point by a specified distance along a given axis.
     *
     * @param d The distance by which to translate the point.
     * @param axis The axis along which to translate ('x', 'y', or 'z').
     * @return 0 if successful, -1 if the axis is invalid.
     */
    int translate(int d, char axis);

    /*
     * Displays the point's coordinates in the format (x, y, z).
     */
    void displayPoint() const;
};

// End of the header guard to prevent multiple inclusions of this file.
#endif