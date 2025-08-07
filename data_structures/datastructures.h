#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include <any>

typedef struct LinkedList LinkedList;
typedef LinkedList* ll_ptr;
ll_ptr initLinkedList;

typedef enum DATATYPE{// Enum to signify what data type the structure will contain.
    SIGNED_INT,       // 0, 4 bytes
    UNSIGNED_INT,     // 1, 4 bytes
    CHAR,             // 2, 1 byte
    SIGNED_CHAR,      // 3, 1 byte
    UNSIGNED_CHAR,    // 4, 1 byte
    SIGNED_SHORT,     // 5, 2 bytes
    UNSIGNED_SHORT,   // 6, 2 bytes
    STRING,           // 7, Dynamic
    CPP_STYLE_STRING, // 8, Dynamic
    BOOLEAN,          // 9, 1 byte
    FLOAT,            // 10, 4 bytes
    DOUBLE            // 11, 8 bytes
}DATATYPE;


enum class Datatypes{   // An enumeration class containing data types, for dereferencing pointers.
    SIGNED_INT,         // 0, 4 bytes
    UNSIGNED_INT,       // 1, 4 bytes
    UNSIGNED_LONG_INT,  // 2, 8 bytes
    CHAR,               // 3, 1 byte
    SIGNED_CHAR,        // 4, 1 byte
    UNSIGNED_CHAR,      // 5, 1 byte
    SIGNED_SHORT,       // 6, 2 bytes
    UNSIGNED_SHORT,     // 7, 2 bytes
    STRING,             // 8, Dynamic
    BOOLEAN,            // 9, 1 byte
    FLOAT,              // 10, 4 bytes
    DOUBLE              // 11, 8 bytes
};

typedef enum STRUCTURE{ // Enum to signify the type of structure.
    LINKEDLIST,         // 0
    STACK,              // 1
    QUEUE,              // 2
    PRIORITY_QUEUE,     // 3
    BINARY_TREE,        // 4
    BINARY_SEARCH_TREE, // 5
    DYNAMIC_ARRAY       // 6
}STRUCTURE;

std::any elementDereferencing(void* element, Datatypes type){ // Function which deferences void pointers based on the enumeration type provided. Utilises switch cases.
    switch (type){
        case Datatypes::SIGNED_INT:{
            return *static_cast<signed int*>(element);
        }
        case Datatypes::UNSIGNED_INT:{
            return *static_cast<unsigned int*>(element);
        }
        case Datatypes::UNSIGNED_LONG_INT:{
            return *static_cast<unsigned long int*>(element);
        }
        case Datatypes::CHAR:{
            return *static_cast<char*>(element);
        }
        case Datatypes::SIGNED_CHAR:{
            return *static_cast<signed char*>(element);
        }
        case Datatypes::UNSIGNED_CHAR:{
            return *static_cast<unsigned char*>(element);
        }
        case Datatypes::SIGNED_SHORT:{
            return *static_cast<signed short*>(element);
        }
        case Datatypes::UNSIGNED_SHORT:{
            return *static_cast<unsigned short*>(element);
        }
        case Datatypes::STRING:{
            return *static_cast<std::string*>(element);
        }
        case Datatypes::BOOLEAN:{
            return *static_cast<bool*>(element);
        }
        case Datatypes::FLOAT:{
            return *static_cast<float*>(element);
        }
        case Datatypes::DOUBLE:{
            return *static_cast<double*>(element);
        }
        default:{
            return{};
        }
    }
}

bool null_check(void* dynamicallyAllocatedMemory);
bool nullptr_check(void* dynamicallyAllocatedMemory);
int returnBytes(DATATYPE types);
