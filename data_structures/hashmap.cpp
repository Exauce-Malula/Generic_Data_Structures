#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

HashMap::HashMap(){                             // Constructor declaration for the hash map.                            
    for (size_t i = 0; i < TABLESIZE; i++){     // Sets all buckets within the hash map as empty.
        table[i] = nullptr;                     // "nullptr" will signify that the bucket is empty.
    }
}

unsigned long HashMap::hash(void* const val, Datatypes valType){     // Declaration of a private method to hash a value.  
    unsigned long hash = 5381;                                       // Initial seed, recommended by DJB2.
    /*
        The switch statement below, based on the type of the value passed, is reinterpreted as an either a string/array of unsigned characters, looping across every
        single character to be hashed, having "hash" equal itself multiplied by 33, plus itself, then the ASCII value of the character.
        If there are multiple characters, then it is iterated over every single character.  
    */
    switch(valType){
        case Datatypes::STRING:{
            std::string* tempStringPtr = static_cast<std::string*>(val);
            std::string tempString = *tempStringPtr;
            for (size_t i = 0; i < tempString.size(); i++){
                hash = ((hash << 5) + hash) + static_cast<unsigned char>(tempString.at(i));
            }
            break;
        }
        case Datatypes::CHAR:{
            char* tempCharPtr = static_cast<char*>(val);
            char tempChar = *tempCharPtr;
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(tempChar);
            break;
        }
        case Datatypes::SIGNED_INT:
        case Datatypes::UNSIGNED_INT:{
            unsigned char* tempIntegerPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(int); i++){
                hash = ((hash << 5) + hash) + tempIntegerPointer[i];
            } 
            break;
        }
        case Datatypes::UNSIGNED_LONG_INT:{
            unsigned char* tempLongIntegerPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(unsigned long int); i++){
                hash = ((hash << 5) + hash) + tempLongIntegerPointer[i];
            } 
            break;
        }
        case Datatypes::UNSIGNED_CHAR:
        case Datatypes::SIGNED_CHAR:{
            unsigned char* tempCharPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(char); i++){
                hash = ((hash << 5) + hash) + tempCharPointer[i];
            } 
            break;
        }
        case Datatypes::SIGNED_SHORT:
        case Datatypes::UNSIGNED_SHORT:{
            unsigned char* tempShortPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(short); i++){
                hash = ((hash << 5) + hash) + tempShortPointer[i];
            } 
            break;
        }
        case Datatypes::BOOLEAN:{
            unsigned char* tempBoolPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(bool); i++){
                hash = ((hash << 5) + hash) + tempBoolPointer[i];
            } 
            break;
        }
        case Datatypes::FLOAT:{
            unsigned char* tempFloatPointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(float); i++){
                hash = ((hash << 5) + hash) + tempFloatPointer[i];
            } 
            break;
        }
        case Datatypes::DOUBLE:{
            unsigned char* tempDoublePointer = reinterpret_cast<unsigned char*>(val);
            for (size_t i = 0; i < sizeof(double); i++){
                hash = ((hash << 5) + hash) + tempDoublePointer[i];
            } 
            break;
        }
        default:{
            throw std::invalid_argument("Invalid datatype provided.");
            break;
        }
    }

    return hash % TABLESIZE;                                         // This is so that the key fits within the table's range.
}

void HashMap::insert(void* val, void* key, Datatypes valType, Datatypes keyType){   // Declaration to insert a value into a bucket within the hash map. Also the setter method.
    unsigned char index = hash(key, keyType);                                       // This contains the hashed value of the key.
    if (table[index] == nullptr){                                                   // Checks if the bucket is currently empty.
        table[index] = new HashMap::hashNode;                                       // Creates new instance of the hash node struct.
        table[index]->next = nullptr;                                               // The pointer to the next hash node is set equal to null, to signify that it points to nothing.
        table[index]->value = nullptr;                                              // The value is set to null, to signify it is empty.
    }
    if (table[index]->value != nullptr){                                            // Condition which checks if the value within the bucket is not empty.
        HashMap::hashNode* tempPointer;                                             // Temporary pointer is created.
        tempPointer = table[index];                                                 // It is set equal to the current bucket.
        while (tempPointer != nullptr){                                             // While loop which traverses through the chaining of the nodes.
            tempPointer = tempPointer->next;                                        // The temporary pointer is set equal to the pointer of the next node.
        }
        tempPointer->next = new HashMap::hashNode;                                  // A new bucket instance is created. 
        tempPointer->next = nullptr;                                                // The next bucket is set to null.
        /*
            The value, key, value type, original key value and key type are set equal to their respective values.
        */
        tempPointer->value = val;                                                   
        tempPointer->key = index;
        tempPointer->valueType = valType;
        tempPointer->originalKeyValue = key;
        tempPointer->keyType = keyType;
    }
    else{
         /*
            Otherwise, the value, key, value type, original key value and key type are set equal to their respective values.
        */
        table[index]->key = index;
        table[index]->value = val;
        table[index]->valueType = valType;
        table[index]->originalKeyValue = key;
        table[index]->keyType = keyType;
    }
}

Stack HashMap::get(void* key, Datatypes keyType){                   // Declaration of a getter method to obtain values from a given key.
    unsigned char index = hash(key, keyType);                       // This contains the hashed value of the key.
    Stack values = Stack();                                         // Stack which collects a set of values from if the list has any chaining.
    HashMap::hashNode* tempPointer = table[index];                  // Temporary pointer which points at the current bucket.
    while (tempPointer != nullptr){                                 // This while loop searches through any chaining.
        values.push(tempPointer->value, tempPointer->valueType);    // The value present alongside its type is pushed onto the stack.
        tempPointer = tempPointer->next;                            // The temporary pointer is set equal to the pointer of the next node.
    }
    return values;                                                  // The stack is returned.
}

bool HashMap::remove(void* key, Datatypes keyType){                 // Declaration of a method to remove a bucket.
    unsigned char index = hash(key, keyType);                       // This contains the hashed value of the key.
    HashMap::hashNode* tempPointer = table[index];                  // Temporary pointer which points at the current bucket.
    HashMap::hashNode* previous = nullptr;                          // A previous node pointer is created to manage traversal.
    while(tempPointer != nullptr){                                  // Loops over the chaining of the bucket.     
        if (tempPointer->key == index){                             // Condition where the key found is in the bucket.
            if (previous == nullptr){                               // Checks whether the previous bucket is equal to null (empty).
                tempPointer = tempPointer->next;                    // Traverses to the next bucket via chaining.
            }
            else{
                previous->next = tempPointer->next;                 // Otherwise, the pointer to the next node for previous is set to the next node for the current bucket.
            }
            switch(tempPointer->valueType){                         // Switch statement to delete the value within the bucket based on it's type.
                case Datatypes::SIGNED_INT:{
                    delete static_cast<signed int*>(tempPointer->value);
                    break;
                }
                case Datatypes::UNSIGNED_INT:{
                    delete static_cast<unsigned int*>(tempPointer->value);
                    break;
                }
                case Datatypes::SIGNED_CHAR:{
                    delete static_cast<signed char*>(tempPointer->value);
                    break;
                }
                case Datatypes::UNSIGNED_CHAR:{
                    delete static_cast<unsigned char*>(tempPointer->value);
                    break;
                }
                case Datatypes::CHAR:{
                    delete static_cast<char*>(tempPointer->value);
                    break;
                }
                case Datatypes::UNSIGNED_LONG_INT:{
                    delete static_cast<unsigned long*>(tempPointer->value);
                    break;
                }
                case Datatypes::FLOAT:{
                    delete static_cast<float*>(tempPointer->value);
                    break;
                }
                case Datatypes::DOUBLE:{
                    delete static_cast<double*>(tempPointer->value);
                    break;
                }
                case Datatypes::BOOLEAN:{
                    delete static_cast<bool*>(tempPointer->value);
                    break;
                }
                case Datatypes::STRING:{
                    delete static_cast<std::string*>(tempPointer->value);
                    break;
                }
                case Datatypes::SIGNED_SHORT:{
                    delete static_cast<signed short*>(tempPointer->value);
                    break;
                }
                case Datatypes::UNSIGNED_SHORT:{
                    delete static_cast<unsigned short*>(tempPointer->value);
                    break;
                }
                default:{
                    throw std::invalid_argument("Invalid datatype provided.");
                    break;
                }
            }
            
            tempPointer->value = nullptr;                            // When fully deleted, the bucket is set to null pointer. 
            return true;                                            // True is returned to confirm that the value was found and deleted.
        }
    }
    return false;                                                   // Otherwise, if the method could not find the value, false is returned.
}

HashMap::~HashMap(){                                                // Declaration of a destructor method.
    for (size_t i = 0; i < TABLESIZE; i++){                         // Loops over the table, calls on the "remove" method.
        remove(table[i]->originalKeyValue, table[i]->keyType);
    }
}


