#include <iostream>
#include <fstream>
#include "screen.h"
#include "shape.cpp"
#include "bunch.cpp"

int main() {
    Screen myscreen;
    myscreen.axes('+');
    Bunch<point> points;
    Bunch<elipse> elipses;
    Bunch<polygon> polygons;
    Bunch<line> lines;

    int selection = 0;

    while (selection != -1) {
        if (selection == 0 or selection == 5) {
            std::cout << "1: draw point\n2: draw elipse\n3: draw polygon\n4: draw line\n";
            std::cout << "6: remove from\n7: display inputed shapes\n";
            std::cout << "8: paint shape\n9: clear screen\n10: save to file\n11: load from file\n";
        }

        std::cout << "Select operation: ";
        std::cin >> selection;

        switch (selection) {
            case 1 : { //add a point to point bunch
                int x, y;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                point p(x, y);
                points.push(p);
                break;
            }
            case 2 : { //add an elipse to elipse bunch
                int x, y, xR, yR;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter X radius:";
                std::cin >> xR;
                std::cout << "enter Y radius:";
                std::cin >> yR;
                elipse e(x, y, xR, yR);
                elipses.push(e);
                break;
            }
            case 3 : { // add a polygon to polygon bunch
                int x, y, n, l;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter number of sides:";
                std::cin >> n;
                std::cout << "enter side length:";
                std::cin >> l;
                polygon pol(x, y, n, l);
                polygons.push(pol);
                break;
            }
            case 4 : { //add a line to line bunch
                int x, y, x2, y2;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter X2:";
                std::cin >> x2;
                std::cout << "enter Y2:";
                std::cin >> y2;
                line l(x, y, x2, x2);
                lines.push(l);
                break;
            }
            case 5: { // draw and display all bunches
                for (int i = 0; i < points.items; i++) {points.list[i].draw(myscreen);}
                for (int i = i = 0; i < elipses.items; i++) {elipses.list[i].draw(myscreen);}
                for (int i = i = 0; i < polygons.items; i++) {polygons.list[i].draw(myscreen);}
                for (int i = i = 0; i < lines.items; i++) {lines.list[i].draw(myscreen);}
                myscreen.display();
                break;
            }
            case 6 : { //remove from selected bunch
                std::cout << "| 1 points | 2 elipses | 3 polygons | 4 lines | -> ";
                int rem;
                std::cin >> rem;
                switch(rem){
                    case 1 : points.remove(); break;
                    case 2 : elipses.remove(); break;
                    case 3 : polygons.remove(); break;
                    case 4 : lines.remove(); break;
                    default: std::cerr << "no bunch selected" << std::endl; break;
                }
                myscreen.clear();
            }
            case 7 : { //show all bunch info

                points.display();

                elipses.display();

                polygons.display();

                lines.display();
                break;
            }
            case 8 : {//paint item (given index)from bunch or all bunches)
                std::cout << "| 1 points | 2 elipses | 3 polygons | 4 lines | -1 all |  -> ";
                int bunchSelect;
                int index = 0;
                std::cin >> bunchSelect;
                if(bunchSelect != -1) {
                    std::cout << "select index (-1 for all) -> ";
                    std::cin >> index;
                }
                    switch(bunchSelect) {
                        case -1:
                            for (int i = 0; i < points.items; i++) { points.list[i].draw(myscreen); }
                            for (int i = i = 0; i < elipses.items; i++) { elipses.list[i].draw(myscreen); }
                            for (int i = i = 0; i < polygons.items; i++) { polygons.list[i].draw(myscreen); }
                            for (int i = i = 0; i < lines.items; i++) { lines.list[i].draw(myscreen); }
                            break;
                        case 1 :
                            if(index == -1){
                                for (int i = 0; i < points.items; i++) { points.list[i].draw(myscreen); }
                            } else {
                                points.list[index].draw(myscreen);
                            }
                            break;
                        case 2 :
                            if(index == -1){
                                for (int i = 0; i < elipses.items; i++) { elipses.list[i].draw(myscreen); }
                            } else {
                                elipses.list[index].draw(myscreen);
                            }
                            break;
                        case 3 :
                            if(index == -1){
                                for (int i = 0; i < polygons.items; i++) { polygons.list[i].draw(myscreen); }
                            } else {
                                polygons.list[index].draw(myscreen);
                            }
                            break;
                        case 4 :
                            if(index == -1){
                                for (int i = 0; i < lines.items; i++) { lines.list[i].draw(myscreen); }
                            } else {
                                lines.list[index].draw(myscreen);
                            }
                            break;
                    }
                myscreen.display();
                break;
            }//END OF CASE 8
            case 9 : {
                myscreen.clear();
                myscreen.display();
                break;
            } case 10 : {//save to file
                std::ofstream outFile;
                std::string filename;
                std::cout << "input file name: ";
                std::cin >> filename;
                outFile.open("shapeTextFiles/" + filename);

                for (int i = 0; i < points.items; i++) { outFile << points[i].info() << std::endl; }
                for (int i = 0; i < elipses.items; i++) { outFile << elipses[i].info() << std::endl; }
                for (int i = 0; i < polygons.items; i++) { outFile << polygons[i].info() << std::endl; }
                for (int i = 0; i < lines.items; i++) { outFile << lines[i].info() << std::endl; }
                break;
            } case 11 : {
                std::string filename;
                std::cout << "enter file name: ";
                std::cin >> filename;
                std::ifstream infile;
                std::string inLine;
                infile.open("shapeTextFiles/" + filename);

                if (!infile.is_open()) {
                    std::cerr << "File does not exist, loading data failed!" << std::endl;
                    break;
                }

                while (!infile.eof()) {
                    // Read a Line from File
                    getline(infile, inLine, ' ');
                    //std::cout << inLine << std::endl;
                    if (inLine.find("point") != std::string::npos) {
                        int x,y;
                        infile >> x >> y;
                        point p(x,y);
                        points.push(p);
                    } else {
                        int x,y,a,b;
                        infile >> x >> y >> a >> b;
                        if (inLine.find("elipse") != std::string::npos) {elipse e(x,y,a,b); elipses.push(e);}
                        if (inLine.find("polygon") != std::string::npos) {polygon pol(x,y,a,b); polygons.push(pol);}
                        if (inLine.find("line") != std::string::npos) {line l(x,y,a,b); lines.push(l);}
                    }
                }
                break;
            }
            default:
                std::cout << "default" << std::endl;
                break;
            }

        }

    }

