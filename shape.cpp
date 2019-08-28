//	point     $
//	elliplse  *
//	polygon   #
//	line      -
#include "screen.h"
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
    void draw(Screen & scr){
        scr.point(x,y,'x');
    }
    void info(){
        std::cout << "("  << getX() << ", " << getY() << ") ";
    }
    ~point(){ std::cout << "object deleted" << std::endl;
    }
private:
    int x;
    int y;
    char symbol = '$';

};


class elipse{
public:
    explicit elipse(int x=0, int y=0, int xRadius=0,int yRadius=0) {
        this->x = x;
        this->y = y;
        this->xRadius = xRadius;
        this->yRadius = yRadius;
        setSymbol('*');
    }
    int getX(){ return x;};
    int getY(){ return y;};
    int getXradius(){ return xRadius; }
    int getYradius(){ return yRadius; }
    char getSymbol(){ return symbol;};
    void setSymbol(char s){ this->symbol = s; }
    void  draw(Screen & scr){ scr.ellipse(getX(),getY(),xRadius,yRadius,'*'); }
    void info(){ std::cout << "(" << getX() << ", " << getY() << ", " << getXradius() << ", " << getYradius() << ") "; }
private:
    int x,y;
    int xRadius;
    int yRadius;
    char symbol = '*';
};

class polygon{
public:
    explicit polygon(int x=0, int y=0, int n=0, int l=0){
        this->x = x;
        this->y = y;
        this->n = n;
        this->l = l;
        setSymbol('#');
    }
    int getX(){ return x;};
    int getY(){ return y;};
    int getSides(){ return n; }
    int getLength(){ return l; }
    void  draw(Screen & scr)  { scr.polygon(getX(),getY(),n,l,'#'); }
    void setSymbol(char s){ this->symbol = s; }
    void info()  { std::cout << "(" << getX() << ", " << getY() << ", " << getSides() << ", " << getLength() << ") "; }

private:
    int x,y,n,l;
    char symbol = '#';
};

class line{
public:
    explicit line(int x=0, int y=0, int x2=0, int y2=0){
        this->x = x;
        this->y = y;
        this->x2 = x2;
        this->y2 = y2;
    }
    int getX(){ return x;};
    int getY(){ return y;};
    int getx2(){ return x2; }
    int gety2(){ return y2; }
    void draw(Screen & scr) { scr.line(getX(),getY(),x2,y2,'-'); }

    void info(){ std::cout << "(" << getX() << ", " << getY() << ", " << getx2() << ", " << gety2() << ") "; }
private:
    int x,y,x2,y2;
};