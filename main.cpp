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

    std::any poppedResult = arr->pop_back();
    std::cout << std::any_cast<int>(poppedResult) << std::endl;

    /* for (size_t i = 0; i < arr->getSize()){
        switch (arr)
    }
    */
    return 0;
}

