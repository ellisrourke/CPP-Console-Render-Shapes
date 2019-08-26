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


    int selection = 0;

    while(selection != -1){
        if(selection == 0 or selection == 5){
            std::cout << "1: draw point\n2: draw elipse\n3: draw polygon\n4: draw line\n";
            std::cout << "5: display current shapes" << std::endl;
        }
        std::cout << "Select operation: " << std::endl;
        std::cin >> selection;

        switch (selection) {
            case 1 : {
                int x, y;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                point p(x, y);
                points.push(p);
                break;
            }
            case 5:
                myscreen.display();
                break;
            case -1:{
                break;
            }
        }
    }

}
