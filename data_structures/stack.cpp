#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

bool Stack::isFull(){           // Method which checks if the stack is full.
    if (utilisedSize >= size){  // Selection; checks if the "utilisedSize" is greater than or equal to "size", returns true.
        return true;
    }
    return false;               // Returns false, this happens when "utilisedSize" is less than "size".
}

Stack::Stack(){                                     // Constructor declaration which instantiates an empty stack with capacity one.
    this->stack = new(std::nothrow) element[1];     // Dynamically allocates memory for an empty stack with size one.
    this->topPointer = stack;                       // Pointer attribute set to the top of the stack.
    this->size = 1;                                 // "size" attribute is set to one.
    this->utilisedSize = 0;                         // "utilisedSize" attribute is set to zero.
}

bool Stack::isEmpty(){          // Method which checks if the stack is empty.
    if (utilisedSize <= 0){     // Selection; checks if the "utilisedSize" is equal to zero, returns true.
        return true;
    }
    return false;               // Returns false, this happens when "utilisedSize" is greater than zero.
}

void Stack::push(void* value, Datatypes type){                          // Method which pushes an element onto the top of the stack.
    if (isFull()){                                                      // Uses selection to check whether the stack is full, this is so that more memory can be allocated to the stack object for more elements to be pushed.
        element* newStack = new(std::nothrow) element[size << 1];       // Creates a new element pointer "newStack", and dynamically allocates double the size of the previous stack.
        std::memcpy(newStack, stack, sizeof(element) * utilisedSize);   // Uses the function "std::memcpy" to copy the previous stack elements to the new stack.
        delete[] stack;                                                 // The old stack is deleted, no longer required.
        stack = newStack;                                               // The stack pointer is set equal to the new stack pointer.
        size = size << 1;                                               // The size is then doubled.
        this->topPointer = this->stack + utilisedSize;                  // Pointer arithmetic; the "topPointer" is now currently pointing at the next available space at the top of the stack.
    }

    this->topPointer->elementPtr = value;                               // The data is set equal to the void pointer parameter "value". 
    this->topPointer->type = type;                                      // The typing is then also set equal to the enum class object parameter "type".
    topPointer++;                                                       // The top pointer moves up to the next free element.
    utilisedSize++;                                                     // The utilised size is incremented by one as one new element has been added to the stack.
}

element Stack::pop(){                                                       // Method which pops an element off the top of the stack.
    if(isEmpty()){                                                          // Uses selection to check whether the stack is empty, "pop" cannot occur if there are no elements on the stack.
        std::cout << "Unable to pop, the stack is empty..." << std::endl;   // Error message telling the user that the stack is unable to be popped.
        return element{nullptr, Datatypes::SIGNED_INT};                     // Nothing is returned.
    }
    else if (utilisedSize <= (size >> 1) && (size != 1)){                   // Selection, else if statement checks if the utilised size of the stack is less than or equal to the size halved, but, "size" cannot be equal to one. 
        element* newStack = new(std::nothrow) element[size >> 1];           // Creates a new element pointer "newStack", and dynamically allocates half the size of the previous stack.
        std::memcpy(newStack, stack, sizeof(element) * utilisedSize);       // Uses the function "std::memcpy" to copy the previous stack elements to the new stack.
        delete[] stack;                                                     // The old stack is deleted, no longer required.
        stack = newStack;                                                   // The stack pointer is set equal to the new stack pointer.
        size = size >> 1;                                                   // The size is then halved.
        this->topPointer = this->stack + utilisedSize;                      // Pointer arithmetic; the "topPointer" is now currently pointing at the next available space at the top of the stack.
    }

    topPointer--;                                                           // The top pointer moves down to the previous element.
    utilisedSize--;                                                         // The utilised size is decremented by one as one element has been removed off the stack.
    return *(topPointer);                                                   // The value which the "topPointer" points to is then returned.
}

element Stack::peek(){                                                      // Method which peeks at an element on top of the stack.
    if(isEmpty()){                                                          // Uses selection to check whether the stack is empty, "peek" cannot occur if there are no elements on the stack.
        std::cout << "Unable to peek, the stack is empty..." << std::endl;  // Error message telling the user that the stack is unable to be peeked.
        return element{nullptr, Datatypes::SIGNED_INT};                     // Nothing is returned.
    }
    return *(topPointer - 1);                                               // The value which the "topPointer" points to is then returned.
}

Stack::~Stack(){                                    // Destructor method to delete/destroy stack object.
    for (size_t i = 0; i < this->size; i++){        // For loop which goes through all elements within the stack.
        if (this->utilisedSize != 0){               // If statement skipping over the switch statement, to avoid default case.
            switch(this->stack[i].type){            // Switch statement based on the type of the data within a stack element.
                case Datatypes::SIGNED_INT:{
                    delete static_cast<signed int*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::UNSIGNED_INT:{
                    delete static_cast<unsigned int*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::UNSIGNED_LONG_INT:{
                    delete static_cast<unsigned long int*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::CHAR:{
                    delete static_cast<char*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::SIGNED_CHAR:{
                    delete static_cast<signed char*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::UNSIGNED_CHAR:{
                    delete static_cast<unsigned char*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::SIGNED_SHORT:{
                    delete static_cast<signed short*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::UNSIGNED_SHORT:{
                    delete static_cast<unsigned short*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::STRING:{
                    delete static_cast<std::string*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::BOOLEAN:{
                    delete static_cast<bool*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::FLOAT:{
                    delete static_cast<float*>(this->stack[i].elementPtr);
                    break;
                }
                case Datatypes::DOUBLE:{
                    delete static_cast<double*>(this->stack[i].elementPtr);
                    break;
                }
                default:{
                    std::cerr << ("Invalid datatype provided.") << std::endl;
                    break;
                }
            }
        }
        this->stack[i].elementPtr = nullptr;        // All element pointers are set equal to null.
    }
    delete[] this->stack;                           // The container for the stack is deleted.
    this->stack = nullptr;                          // The pointer pointing to the stack is set to null.
}


