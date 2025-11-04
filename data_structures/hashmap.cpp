#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

HashMap::HashMap(){
    for (size_t i = 0; i < TABLESIZE; i++){
        table[i] = nullptr;
    }
}

unsigned long HashMap::hash(void* const val, Datatypes valType){
    unsigned long hash = 5381;
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

    return hash % TABLESIZE;
}

void HashMap::insert(void* val, void* key, Datatypes valType, Datatypes keyType){
    unsigned char index = hash(key, keyType);
    if (table[index] == nullptr){
        table[index] = new HashMap::hashNode;
        table[index]->next = nullptr;
        table[index]->value = nullptr;
    }
    if (table[index]->value != nullptr){
        HashMap::hashNode* tempPointer;
        tempPointer = table[index];
        while (tempPointer != nullptr){
            tempPointer = tempPointer->next;
        }
        tempPointer->next = new HashMap::hashNode;
        tempPointer->next = nullptr;
        tempPointer->value = val;
        tempPointer->key = index;
        tempPointer->valueType = valType;
        tempPointer->originalKeyValue = key;
        tempPointer->keyType = keyType;
    }
    else{
        table[index]->key = index;
        table[index]->value = val;
        table[index]->valueType = valType;
        table[index]->originalKeyValue = key;
        table[index]->keyType = keyType;
    }
}

Stack HashMap::get(void* key, Datatypes keyType){
    unsigned char index = hash(key, keyType);
    Stack values = Stack();
    HashMap::hashNode* tempPointer = table[index];
    while (tempPointer != nullptr){
        values.push(tempPointer->value, tempPointer->valueType);
        tempPointer = tempPointer->next;
    }
    return values;
}

bool HashMap::remove(void* key, Datatypes keyType){
    unsigned char index = hash(key, keyType);
    HashMap::hashNode* tempPointer = table[index];
    HashMap::hashNode* previous = nullptr;
    while(tempPointer != nullptr){
        if (tempPointer->key == index){
            if (previous == nullptr){
                tempPointer = tempPointer->next;
            }
            else{
                previous->next = tempPointer->next;
            }
            switch(tempPointer->valueType){
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
            tempPointer = nullptr;
            return true;
        }
    }
    return false;
}

HashMap::~HashMap(){
    for (size_t i = 0; i < TABLESIZE; i++){
        remove(table[i]->originalKeyValue, table[i]->keyType);
    }
}


