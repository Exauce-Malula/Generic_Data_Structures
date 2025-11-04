#include <iostream>
#include "data_structures/datastructures.h"

int main(){
    DynArray* arr = new DynArray();             // Instantiate a new "DynArray" object "arr".
    
    std::cout << arr->isEmpty() << std::endl;   // Attempt to check if the array is empty by calling upon the method "isEmpty". 

    for (int i = 1; i < 6; i++){                // For loop to attempt to add numbers 1 to 6 to the dymanic array.
        int* element = new int(i);
        arr->push_back(element, Datatypes::SIGNED_INT);
    }

    std::cin.get();

    arr->setElement(0, new float(2.4), Datatypes::FLOAT);
    arr->setElement(1, new std::string ("TEST"), Datatypes::STRING);

    std::cin.get();

    element poppedElement = arr->pop_back();
    int* poppedValue = static_cast<int*>(poppedElement.elementPtr);
    std::cout << *poppedValue << std::endl;

    std::cin.get();

    for (size_t i = 0; i < arr->getUtilisedSize(); i++){
        element retrievedElement = arr->getElement(i);
        switch(retrievedElement.type){
            case Datatypes::SIGNED_INT:{
                int* retrievedInt = static_cast<int*>(retrievedElement.elementPtr);
                std::cout << *retrievedInt << ", ";
                break;
            }
            case Datatypes::FLOAT:{
                float* retrievedFloat = static_cast<float*>(retrievedElement.elementPtr);
                std::cout << *retrievedFloat << ", ";
                break;
            }
            case Datatypes::STRING:{
                std::string* retrievedString = static_cast<std::string*>(retrievedElement.elementPtr);
                std::cout << *retrievedString << ", ";
                break;
            }
        }
    }
    std::cout << "\nSize = " << int(arr->getSize()) << ".\nUtilised Size: " << int(arr->getUtilisedSize()) << std::endl;

    delete arr;
    std::cin.get();
    arr = nullptr;
    return 0;
}

