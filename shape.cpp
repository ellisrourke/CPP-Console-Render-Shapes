//	point     $
//	elliplse  *
//	polygon   #
//	line      -
#include "screen.h"
#include <sstream>
class point{
public:
    explicit point(int x=0,int y=0){
        this->x = x;
        this->y = y;
    }
    //copy constructor
    point(point const & that) : point(that.x, that.y){}
    //move constructor
    point(point && that) noexcept{
        this->x = that.x;
        this->y = that.y;
        that.x =0;
        that.y=0;
    }
    //copy assignment
    point &operator = (point const & that){
        if(this != &that){
            x = that.x;
            y = that.y;
        }
        return *this;
    }
    //move assignment
    point &operator = (point && that) noexcept {
        x = that.x;
        y = that.y;
        that.x = 0;
        that.y = 0;
        return *this;
    }
    //destructor
    ~point() = default;

    int getX(){ return x;};
    int getY(){ return y;};
    void draw(Screen & scr){
        scr.point(x,y,'x');
    }
    std::string getType(){ return type;};
    std::string info(){
        std::stringstream data;
        data<< getType() << " " << getX() << " " << getY();
        std::string out = data.str();
        return out;
    }
private:
    int x;
    int y;
    std::string type = "point";

};

class elipse{
public:
    explicit elipse(int x=0, int y=0, int xRadius=0,int yRadius=0) {
        this->x = x;
        this->y = y;
        this->xRadius = xRadius;
        this->yRadius = yRadius;
    }
    //copy constructor
    elipse(elipse const & that) : elipse(that.x, that.y, that.xRadius, that.yRadius){}
    //move constructor
    elipse(elipse && that) noexcept{
        this->x = that.x;
        this->y = that.y;
        this->xRadius = that.xRadius;
        this->yRadius = that.yRadius;
        that.x = 0;
        that.y = 0;
        that.xRadius = 0;
        that.yRadius = 0;
    }
    //copy assignment
    elipse &operator = (elipse const & that){
        if(this != &that){
            x = that.x;
            y = that.y;
            xRadius = that.xRadius;
            yRadius = that.yRadius;
        }
        return *this;
    }
    //move assignment
    elipse &operator = (elipse && that) noexcept {
        x = that.x;
        y = that.y;
        xRadius = that.xRadius;
        yRadius = that.yRadius;

        that.x=0;
        that.y=0;
        that.xRadius=0;
        that.yRadius=0;

        return *this;
    }
    //destructor
    ~elipse() = default;
    int getX(){ return x;};
    int getY(){ return y;};
    int getXradius(){ return xRadius; }
    int getYradius(){ return yRadius; }
    void  draw(Screen & scr){ scr.ellipse(getX(),getY(),xRadius,yRadius,'*'); }
    std::string info() {
        std::stringstream data;
        data<< getType() << " " << getX() << " " << getY() << " " << getXradius() << " " << getYradius();
        std::string out = data.str();
        return out;
    }
    std::string getType() { return type;}
private:
    int x,y;
    int xRadius;
    int yRadius;
    std::string type = "elipse";
};

class polygon{
public:
    explicit polygon(int x=0, int y=0, int n=0, int l=0){
        this->x = x;
        this->y = y;
        this->n = n;
        this->l = l;
    }
    //copy constructor
    polygon(polygon const & that) : polygon(that.x, that.y, that.n, that.l){}
    //move constructor
    polygon(polygon && that) noexcept {
        this->x = that.x;
        this->y = that.y;
        this->n = that.n;
        this->l = that.l;

        that.x = 0;
        that.y = 0;
        that.n = 0;
        that.l = 0;
    }
    //copy assignment
    polygon &operator = (polygon const & that){
        if(this != & that){
            x = that.x;
            y = that.y;
            n = that.n;
            l = that.l;
        }
        return *this;
    }
    //move assignment
    polygon &operator = (polygon && that) noexcept {
        x = that.x;
        y = that.y;
        n = that.n;
        l = that.l;
        that.x = 0;
        that.y = 0;
        that.n = 0;
        that.l = 0;

        return *this;
    }
    //destructor
    ~polygon() = default;
    int getX(){ return x;};
    int getY(){ return y;};
    int getSides(){ return n; }
    int getLength(){ return l; }
    void  draw(Screen & scr)  { scr.polygon(getX(),getY(),n,l,'#'); }
    std::string info(){
        std::stringstream data;
        data<< getType() << " " << getX() << " " << getY() << " " << getSides() << " " << getLength();
        std::string out = data.str();
        return out;
    }
    std::string getType() { return type;}

private:
    int x,y,n,l;
    std::string type = "polygon";
};

class line{
public:
    explicit line(int x=0, int y=0, int x2=0, int y2=0){
        this->x = x;
        this->y = y;
        this->x2 = x2;
        this->y2 = y2;
    }
    //copy constructor
    line(line const & that) : line(that.x, that.y, that.x2, that.y2){}
    //move constructor
    line(line && that) noexcept {
        this->x = that.x;
        this->y = that.y;
        this->x2 = that.x2;
        this->y2 = that.y2;

        that.x=0;
        that.y=0;
        that.x2=0;
        that.y2=0 ;
    }
    //copy assignment
    line &operator = (line const & that){
        if(this != &that) {
            this->x = that.x;
            this->y = that.y;
            this->x2 = that.x2;
            this->y2 = that.y2;
        }
        return *this;
    }
    //move assignment
    line &operator = (line && that) noexcept {
        this->x = that.x;
        this->y = that.y;
        this->x2 = that.x2;
        this->y2 = that.y2;

        this->x=0;
        this->y=0;
        this->x2=0;
        this->y2=0;

        return *this;
    }
    //destructor
    ~line() = default;
    int getX(){ return x;};
    int getY(){ return y;};
    int getx2(){ return x2; }
    int gety2(){ return y2; }
    void draw(Screen & scr) { scr.line(getX(),getY(),x2,y2,'-'); }

    std::string info() {
        std::stringstream data;
        data << getType()  << " " << getX() << " " << getY() << " " << getx2() << " " << gety2();
        std::string out = data.str();
        return out;
    }
    std::string getType(){ return type;}
private:
    int x,y,x2,y2;
    std::string type = "line";
};