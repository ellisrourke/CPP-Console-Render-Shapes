#ifndef GEOMETRICSHAPES_SHAPE_H
#define GEOMETRICSHAPES_SHAPE_H
//	point     $
//	elliplse  *
//	polygon   #
//	line      -
#include <iostream>

class point{
public:
    point(int x,int y){
        this->x = x;
        this->y = y;
    }
    int getX(){ return x;};
    int getY(){ return y;};
    char getSymbol(){ return symbol;};
    void setSymbol(char s){ this->symbol = s; }

private:
    int x;
    int y;
    char symbol = '$';

};

class elipse : public point{
public:
    elipse(int x, int y, int xRadius,int yRadius) : point(x,y){
        this->xRadius = xRadius;
        this->yRadius = yRadius;
        setSymbol('*');
    }
    int getXradius(){ return xRadius; }
    int getYradius(){ return yRadius; }

private:
    int xRadius;
    int yRadius;

};

class polygon : public point{
public:
    polygon(int x, int y, int n) : point(x,y){
        this->n = n;
        setSymbol('#');
    }
    int getSides(){ return n; }

private:
    int n;
};

class line : public point{
public:
    line(int x, int y, int x2, int y2) : point(x,y){
        this->x2 = x2;
        this->y2 = y2;
    }
private:
    int x2;
    int y2;
};

#endif //GEOMETRICSHAPES_SHAPE_H
