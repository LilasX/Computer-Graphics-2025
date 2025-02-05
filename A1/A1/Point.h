#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        int x;
        int y;
        int z;
    
    public:
        Point();

        Point(int xParameter, int yParameter, int zParameter);

        ~Point();

        int translate(int d, char axis);
};

#endif