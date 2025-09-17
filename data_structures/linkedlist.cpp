#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

LinkedList::LinkedList(void* data, Datatypes type){   // Constructor declaration which instantiates a single node pointing to "nullptr".
    val.data = data;                                  // Sets the node's data to the void pointer.
    val.type = type;                                  // Sets the typing of the data to "type", provided by parameter passing.
    next = nullptr;                                   // Sets the next node to NULL, terminating pointer.
}

LinkedList* LinkedList::initLinkedList(size_t size){    // Function method declaration which initalises a linked list.
    LinkedList* head = nullptr;                         // Head of the Linked List is set to nullptr to begin with.    
    LinkedList* tail = nullptr;                         // Tail of the Linked List is set to nullptr to begin with. 

    if (size <= 0){                                     // Case where the size is less than or equal to zero,
        return nullptr;
    }

    for (size_t i = 0; i < size; i++){
        Datatypes typeProvided;
        void* elementProvided;

        std::cin >> typeProvided;

        switch(typeProvided){
            case Datatypes::SIGNED_INT:{
                signed int* element = new signed int;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::SIGNED_CHAR:{
                signed char* element = new signed char;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::SIGNED_SHORT:{
                signed short* element = new signed short;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::UNSIGNED_INT:{
                unsigned int* element = new unsigned int;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::UNSIGNED_CHAR:{
                unsigned char* element = new unsigned char;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::UNSIGNED_SHORT:{
                unsigned short* element = new unsigned short;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::UNSIGNED_LONG_INT:{
                unsigned long* element = new unsigned long;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::CHAR:{
                char* element = new char;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::STRING:{
                std::string* element = new std::string;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::BOOLEAN:{
                bool* element = new bool;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::FLOAT:{
                float* element = new float;
                std::cin >> *element;
                elementProvided = element;
            }
            case Datatypes::DOUBLE:{
                double* element = new double;
                std::cin >> *element;
                elementProvided = element;
            }

        }
        LinkedList* newNode = new LinkedList();
    }
}