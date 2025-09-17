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
    this->stack = new(std::nothrow) element[1];
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
        element* newStack = new(std::nothrow) element[size << 1];
        std::memcpy(newStack, stack, sizeof(element) * utilisedSize);
        delete[] stack;
        stack = newStack;
        size = size << 1;
        this->topPointer = this->stack + utilisedSize;
    }

    this->topPointer->data = value;
    this->topPointer->type = type;
    topPointer++;

}

Stack::element Stack::pop(){
    if(isEmpty()){
        std::cout << "Unable to pop, the stack is empty..." << std::endl;
        return;
    }
    else if (utilisedSize <= (size >> 1)){
        element* newStack = new(std::nothrow) element[size << 1];
        std::memcpy(newStack, stack, sizeof(element) * utilisedSize);
        delete[] stack;
        stack = newStack;
        size = size >> 1;
        this->topPointer = this->stack - utilisedSize;
    }

    topPointer--;
    return *(topPointer + 1);
}

Stack::element Stack::peek(){
    if(isEmpty()){
        std::cout << "Unable to peek, the stack is empty..." << std::endl;
        return;
    }
    return *(topPointer - 1);
}

Stack::~Stack(){
    delete[] stack;
    stack = nullptr;
}


