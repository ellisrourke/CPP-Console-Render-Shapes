#include <iostream>
template <class classType> class Bunch{
public:
    //classType list;
    int items;
    const int cap = 32;
    classType *list;

    Bunch(){
        items = 0;
        list = new classType[cap];
    }



    classType &operator[](int i){return list[i];}

    void push(classType x){
        items+=1;
        list[items - 1] = x;
    };

    classType pop(){
        if(items <= 0)
            return 0;
        items -= 1;
        return list[items];
    };

    classType nextPop(){
        return list[items-1];
    }

    void display(){
        for(int i=0;i<items;i++){
            std::cout << list[i].getX() << list[i].getY() << " ";
        }
        std::cout << std::endl;
    }

};