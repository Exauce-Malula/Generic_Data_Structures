#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include <any>
#include <cstddef>
#include <new>

/* typedef struct LinkedList LinkedList;
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
*/

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

inline std::any elementDereferencing(void* element, Datatypes type){ // Function which deferences void pointers based on the enumeration type provided. Utilises switch cases.
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

// bool null_check(void* dynamicallyAllocatedMemory);
// bool nullptr_check(void* dynamicallyAllocatedMemory);
// int returnBytes(DATATYPE types);

// Struct definition for an element:
typedef struct element{
    void* element;
    Datatypes type;
}element;

// Dynamic Array class declaration:
class DynArray{
     private:
        struct element{         // Struct which contains information for an individual element.
            void* elementPtr;   // The void pointer which points to memory, can be of anything, however, requires casting when dereferencing.
            Datatypes type;     // The enum object, signifies what type the void pointer needs to be dereferenced to.
        };

        element* array;                 // Pointer for the dynamic array; this is so memory can be dynamically allocated.
        unsigned char size;             // Unsigned character, keeps count of the POTENTIAL maximum size of the array.  
        unsigned char utilisedSize;     // Unsigned character, keeps count of elements that are currently used within the array.

        bool isFull();                  // Method which checks if the dynamic array is full.
        void doubleSize();              // Method which doubles the size of the dynamic array when it is full.
        void halfSize();                // Method which halves the size of the dynamic array.

    public:
        DynArray();                                                     // Constructor declaration when instantiating the "DynArray" class.
        bool isEmpty();                                                 // Method which checks if the dynamic array is empty.
        void push_back(void* element, Datatypes type);                  // Method which appends an element to the end of the array.
        std::any pop_back();                                            // Method which removes an element from the end of the array.
        unsigned char getSize();                                        // Returns the current size of the array.
        unsigned char getUtilisedSize();                                // Returns the utilised size of the array.
        std::any getElement(size_t index);                              // Returns the element of any given index.
        void setElement(size_t index, void* element, Datatypes type);   // Method which inserts an element with a given index.
        ~DynArray();                                                    // Destructor method, used whenever deleting dynamic array.
};

// Linked List class declaration:
class LinkedList{
    private:
        struct nodeData{        // Struct which contains information for an individual node.
            void* data;         // The void pointer which points to memory, can be of anything, however, requires casting when dereferencing.
            Datatypes type;     // The enum object, signifies what type the void pointer needs to be dereferenced to.
        };

        nodeData val;           // This is the value present within a node.
        LinkedList* next;       // This pointer points to the next node, will be "nullptr" at the end.

    public:
        LinkedList(void* data, Datatypes type);                        // Constructor declaration which instantiates a single node pointing to "nullptr".
        static LinkedList* initLinkedList(size_t size);                // Function method declaration which initalises a linked list.
        void insert_element_LinkedList(void* data, Datatypes type);    // Procedure method declaration, inserts a node at the head of the Linked List.
        void print_LinkedList();                                       // Procedure which prints the entirity of the Linked List. 
        ~LinkedList();
};

/*
// Struct defintion for data contained within a node:
typedef struct nodeData{
    void* data;
    Datatypes type;
}nodeData;
*/

// Stack class declaration:
class Stack{
    private:
        struct element{
            void* data; 
            Datatypes type;
        };

        element* stack;
        element* topPointer;
        unsigned char size;
        unsigned char utilisedSize;

        bool isFull();
    
    public:
        Stack();
        bool isEmpty();
        void push(void* value, Datatypes type);
        element pop();
        element peek();
        ~Stack();
};