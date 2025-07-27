#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

class DynArray{
    private:
        struct element{         // Struct which contains information for an individual element.
            void* elementPtr;   // The void pointer which points to memory, can be of anything, however, requires casting when dereferencing.
            Datatypes type;     // The enum object, signifies what type the void pointer needs to be dereferenced to.
        };

        element* array;                 // Pointer for the dynamic array; this is so memory can be dynamically allocated.
        unsigned char size;             // Unsigned character, keeps count of the POTENTIAL maximum size of the array.  
        unsigned char utilisedSize;     // Unsigned character, keeps count of elements that are currently used within the array.

        bool isFull(){                  // Method which checks if the dynamic array is full.
            if (utilisedSize >= size){
                return true;            // Returns true is the dynamic array is full.
            }
            return false;               // Otherwise, returns false.
        }

        void doubleSize(){                                              // Method which doubles the size of the dynamic array when it is full.
            element* newArray = new element[size << 1];                 // Bitshift left once to double the size of the array.
            std::memcpy(newArray, array, (sizeof(element) * size));     // std::memcpy copies the memory addresses of the elements from the old array to the newArray.
            delete[] array;                                             // Delete the old array, copy is already made, want to save, not waste memory.
            this->array = newArray;                                     // Set the current instance of the array to the newly allocated array.
            size <<= 1;                                                 // The size of the array is then doubled.
        }

        
};
