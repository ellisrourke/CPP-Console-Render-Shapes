#include <iostream>
#include "screen.h"
#include "shape.cpp"
#include "bunch.cpp"
// main function
int main()
{
    Screen myscreen;
    Bunch<point> points;
    Bunch<elipse> elipses;
    Bunch<polygon> polygons;
    Bunch<line> lines;

    point p(1,2);
    point t(4,3);
    points.push(p);
    points.push(t);
    myscreen.display();
     

}
