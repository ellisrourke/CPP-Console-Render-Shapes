#include <iostream>
#include "screen.h"
#include "shape.h"
// main function
int main()
{
    Screen myscreen;
    point p(15,2);
    point g(15,6);
    elipse e(13,3,5,5);
    p.draw(myscreen);
    g.draw(myscreen);
    e.draw(myscreen);
    polygon pol(-6,0,6,8);
    pol.draw(myscreen);
    //s.point(1,2,'o');

    myscreen.display();
}
