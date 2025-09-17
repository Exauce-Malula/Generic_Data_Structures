#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

bool Stack::isFull(){
    if (utilisedSize >= size){
        return true;
    }
    return false;
}

Stack::Stack(){
    this->stack = new(std::nothrow) Stack[1];
    this->topPointer = stack;
    this->size = 1;
    this->utilisedSize = 0;
}

bool Stack::isEmpty(){
    if (utilisedSize <= 0){
        return true;
    }
    return false;
}

void Stack::push(void* value, Datatypes type){
    if (isFull()){
        element* newStack = new(std::nothrow) Stack[size << 1];
        std::memcpy(newStack, stack, sizeof(stack));
        delete[] stack;
        stack = newStack;
        size = size << 1;
    }

    // Will need to add dereferencing.....
}

element Stack::pop(){

}

element Stack::peek(){

}

Stack::~Stack(){
    delete[] stack;
    stack == nullptr;
}


