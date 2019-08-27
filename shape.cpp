#ifndef GEOMETRICSHAPES_SHAPE_H
#define GEOMETRICSHAPES_SHAPE_H
#include <iostream>
#include "screen.h"
//	point     $
//	elliplse  *
//	polygon   #
//	line      -

class point{
public:
    explicit point(int x=0,int y=0){
        this->x = x;
        this->y = y;
    }
    int getX(){ return x;};
    int getY(){ return y;};
    char getSymbol(){ return symbol;};
    void setSymbol(char s){ this->symbol = s; }

    virtual void draw(Screen & scr){
        scr.point(x,y,'x');
    }

private:
    int x;
    int y;
    char symbol = '$';

};

class elipse : public point{
public:
    explicit elipse(int x=0, int y=0, int xRadius=0,int yRadius=0) : point(x,y){
        this->xRadius = xRadius;
        this->yRadius = yRadius;
        setSymbol('*');
    }
    int getXradius(){ return xRadius; }
    int getYradius(){ return yRadius; }
    void  draw(Screen & scr) override {
        scr.ellipse(getX(),getY(),xRadius,yRadius,'*');
    }
private:
    int xRadius;
    int yRadius;

};

class polygon : public point{
public:
    explicit polygon(int x=0, int y=0, int n=0, int l=0) : point(x,y){
        this->n = n;
        this->l = l;
        setSymbol('#');
    }
    int getSides(){ return n; }
    int getLength(){ return l; }
    void  draw(Screen & scr) override {
        scr.polygon(getX(),getY(),n,l,'#');
    }

private:
    int n;
    int l;
};

class line : public point{
public:
    explicit line(int x=0, int y=0, int x2=0, int y2=0) : point(x,y){
        this->x2 = x2;
        this->y2 = y2;
    }
    void draw(Screen & scr) override {
        scr.line(getX(),getY(),x2,y2,'-');
    }
private:
    int x2;
    int y2;
};

#endif //GEOMETRICSHAPES_SHAPE_H
