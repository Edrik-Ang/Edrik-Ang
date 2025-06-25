//point.header implementation file
// Used to represent a point on a line plot
// Used for plotting the linear regression line in task 4.
//own code
#pragma once
#include <cmath>

class Point {
    public:
        int x; //integer value of x value

        float actual; //Exact float value of y value

        char symbol; //symbol to represent point on plot (e.g 'x" or 'o')

    Point(int _x, float _actual, char _symbol): x(_x), actual(_actual), symbol(_symbol) 
    {}
};
//end of own code
