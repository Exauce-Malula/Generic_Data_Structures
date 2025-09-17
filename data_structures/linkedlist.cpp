#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

LinkedList::LinkedList(void* data, Datatypes type){   // Constructor declaration which instantiates a single node pointing to "nullptr".
    this->val.data = data;                            // Sets the node's data to the void pointer.
    this->val.type = type;                            // Sets the typing of the data to "type", provided by parameter passing.
    this->next = nullptr;                             // Sets the next node to NULL, terminating pointer.
}

LinkedList* LinkedList::initLinkedList(size_t size){    // Function method declaration which initalises a linked list.
    LinkedList* head = nullptr;                         // Head of the Linked List is set to nullptr to begin with.    
    LinkedList* tail = nullptr;                         // Tail of the Linked List is set to nullptr to begin with. 

    if (size <= 0){                                     // Case where the size is less than or equal to zero,
        return nullptr;
    }

    for (size_t i = 0; i < size; i++){                                  // For loop adds nodes based on the "size" provided.
        int typingNumber;                                               // This variable is used to select a data type.
        std::cin >> typingNumber;
        Datatypes typeProvided = static_cast<Datatypes>(typingNumber);  // The integer is then casted to a type provided by the enum class "Datatypes".

        void* elementProvided;                                          // This void pointer is used to contain the actual data of the node being chained.

        /* The switch statement below is an attempt for a user to input their data/value, then 
           a pointer will point to that input. "elementProvided" is then set equal to that pointer,
           so it can be stored within the node.
        */

        switch(typeProvided){
            case Datatypes::SIGNED_INT:{
                signed int* element = new signed int;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::SIGNED_CHAR:{
                signed char* element = new signed char;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::SIGNED_SHORT:{
                signed short* element = new signed short;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::UNSIGNED_INT:{
                unsigned int* element = new unsigned int;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::UNSIGNED_CHAR:{
                unsigned char* element = new unsigned char;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::UNSIGNED_SHORT:{
                unsigned short* element = new unsigned short;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::UNSIGNED_LONG_INT:{
                unsigned long* element = new unsigned long;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::CHAR:{
                char* element = new char;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::STRING:{
                std::string* element = new std::string;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::BOOLEAN:{
                bool* element = new bool;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::FLOAT:{
                float* element = new float;
                std::cin >> *element;
                elementProvided = element;
                break;
            }
            case Datatypes::DOUBLE:{
                double* element = new double;
                std::cin >> *element;
                elementProvided = element;
                break;
            }

        }

        LinkedList* newNode = new LinkedList(elementProvided, typeProvided);    // A new node is instantiated.
        if (head == nullptr){                                                   // Checks if the head is equal to "nullptr" (empty).
            head = newNode;
            tail = newNode;
        }                                                                       // Both "head" and "tail" are set to the new node, where both point to "nullptr". 
        tail->next = newNode;                                                   // The pointer to the tail is set to the new node.
        tail = newNode;                                                         // The tail is also set to the new node.
    }
    return head;                                                                // The head is returned.
}

// Comment on init method at school...
// Also comment on destructor method (finish it as well please) and print method...

void LinkedList::insert_element_LinkedList(void* data, Datatypes type){     // Procedure method declaration, inserts a node at the head of the Linked List.
    if (this == nullptr){                                                   // If the current instance of the Linked List is "nullptr" (empty), then the method stops, returns nothing.
        return;
    }
    LinkedList* temp = this;                                                // A temporary Linked List is created and is set equal to the current instance Linked List.
    while(temp != nullptr){                                                 // While loop which goes through every single Linked list node, until reaching "nullptr", to terminate the loop.
        switch(temp->val.type){                                             // Switch to determine what type the data is, then proceeds to dereference the void pointers and prints the value out.
            case Datatypes::SIGNED_INT:{
                std::cout << *(signed int*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::UNSIGNED_INT:{
                std::cout << *(unsigned int*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::UNSIGNED_LONG_INT:{
                std::cout << *(unsigned long*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::CHAR:{
                std::cout << *(char*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::SIGNED_CHAR:{
                std::cout << *(signed char*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::UNSIGNED_CHAR:{
                std::cout << *(unsigned char*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::SIGNED_SHORT:{
                std::cout << *(signed short*)(temp->val.data) << " -> ";
                break;
            } 
            case Datatypes::UNSIGNED_SHORT:{
                std::cout << *(unsigned short*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::STRING:{
                std::cout << *(std::string*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::BOOLEAN:{
                std::cout << *(bool*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::FLOAT:{
                std::cout << *(float*)(temp->val.data) << " -> ";
                break;
            }
            case Datatypes::DOUBLE:{
                std::cout << *(double*)(temp->val.data) << " -> ";
                break;
            }
        }
    }
    std::cout << "nullptr." << std::endl;                                   // Concludes by printing nullptr.
}    

LinkedList::~LinkedList(){
    switch(val.type){
        case Datatypes::SIGNED_INT:{
            delete static_cast<signed int*>(val.data);
            break;
        }
        case Datatypes::UNSIGNED_INT:{
            delete static_cast<unsigned int*>(val.data);
            break;
        }
        case Datatypes::UNSIGNED_LONG_INT:{
            delete static_cast<unsigned long int*>(val.data);
            break;
        }
        case Datatypes::CHAR:{
            delete static_cast<char*>(val.data);
            break;
        }
        case Datatypes::SIGNED_CHAR:{
            delete static_cast<signed char*>(val.data);
            break;
        }
         case Datatypes::UNSIGNED_CHAR:{
            delete static_cast<signed char*>(val.data);
            break;
        }
         case Datatypes::SIGNED_SHORT:{
            delete static_cast<signed short*>(val.data);
            break;
        }
        case Datatypes::UNSIGNED_SHORT:{
            delete static_cast<unsigned short*>(val.data);
            break;
        }
        case Datatypes::STRING:{
            delete static_cast<std::string*>(val.data);
            break;
        }
        case Datatypes::BOOLEAN:{
            delete static_cast<bool*>(val.data);
            break;
        }
        case Datatypes::FLOAT:{
            delete static_cast<float*>(val.data);
            break;
        }
        case Datatypes::DOUBLE:{
            delete static_cast<double*>(val.data);
            break;
        }
    }

    delete next;
}