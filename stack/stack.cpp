//31번
#include "stack.h"
#include <iostream>
using namespace std;

    Stack::Stack(int maxSize) : maxSize(maxSize), top(-1) {
        data = new int [maxSize];
    }

    Stack::~Stack(){
        delete[] data;
    }
    
    void Stack::push(int value){
        if(isFull())return;
        data[++top] = value;
    }
    
    int Stack::pop(){
        if(isEmpty())return 0;
        return data[top--];
    }
    
    int Stack::peek(){
        if(isEmpty()) return 0;
        return data[top];
    }
    
    bool Stack::isEmpty(){
        return (top == -1);
    }
    
    bool Stack::isFull(){
        return (top == maxSize-1);
    }
    
    int Stack::size(){  
        return top+1;
    }

    void Stack::print(){
    for(int i = top; i >= 0; i--){
        cout << data[i] << endl;
    }
}