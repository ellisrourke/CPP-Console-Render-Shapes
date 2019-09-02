
#include <iostream>
#include "shape.cpp"
#define SIZE 32
template <class T> class Bunch
{

private:

    T num[SIZE];
    int top;


public:

    Bunch() {    //def constr
        top = -1;
    }

    void add(T n) {
        //check stack is full or not
        //if (isFull()) {
        //    return 0;
        //}
        ++top;
        num[top] = n;
        //return n;
    }

    int remove() {

        //to store which n is deleted
        int temp;
        //check for empty
        if (isEmpty())
            return 0;
        temp = num[top];  //temp e il valore e poppato
        num[top] = 0;
        --top;
        return temp;
    }

    int isEmpty() {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isFull() {
        if (top == (SIZE - 1))
            return 1;
        else
            return 0;
    }

    int getsize() {
        return top + 1;
    }

    int& operator[] (T index) {
        if (index >= top + 1)
        {
            std::cout << "Array index out of bound, exiting";
        }
        return num[index - 1];
    }

};