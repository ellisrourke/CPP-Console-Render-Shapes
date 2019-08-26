#include <iostream>
template <class classType> class Bunch{
public:
    classType *list;
    int items;
    Bunch(){
        list[32];
        items = 0;
    }

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
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
};