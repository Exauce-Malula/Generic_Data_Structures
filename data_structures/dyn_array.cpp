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

        void halfSize(){                                                // Method which halves the size of the dynamic array.
            element* newArray = new element[size >> 1];                 // Bitshift right once to halve the size of the array, dynamically allocated memory to a new element pointer.
            std::memcpy(newArray, array, (sizeof(element) * size));     // std::memcpy copies the memory addresses of the elements from the old array to the newArray.
            delete[] array;                                             // Delete the old array, copy is already made, want to save, not waste memory.
            this->array = newArray;                                     // Set the current instance of the array to the newly allocated array.
            size >>= 1;                                                 // The size of the array is then halved.
        }
    
    public:
        DynArray(){                         // Constructor declaration when instantiating the "DynArray" class.
            this->array = new element[1];   // Dynamically allocates new memory for one new element.
            this->size = 1;                 // The size is set to one.
            this->utilisedSize = 0;         // The utilisedSize is set to zero.
        }

        bool isEmpty(){                 // Method which checks if the dynamic array is empty. 
            if (utilisedSize == 0){     // Selection; checks if the utilisedSize is equal to zero, returns true.
                return true;
            }
            return false;               // Returns false, this happens when utilisedSize is greater than zero.
        }

        void push_back(void* element, Datatypes type){      // Method which appends an element to the end of the array.
            if (size >= 128){                               // [NOT FINAL], if statement preventing the dynamic array from resizing further. 
                std::cout << "REACHED MAXIMUM SIZE LIMIT";
                exit(1);                                    // [NOT FINAL], exits the program.
            }
            else if (isFull()){                             // Else, if the method "isFull()" returns true, the array is then resized.
                doubleSize();
            }

            array[utilisedSize].elementPtr = element;       // Sets the specific element's element within the record (struct).
            array[utilisedSize].type = type;                // Sets the specific element's datatype within the record (struct).
            utilisedSize++;                                 // Increments the utilised size by one.
        }

        std::any pop_back(){                                                                                    // Method which removes an element from the end of the array.
            if (!isEmpty()){                                                                                    // Checks if the array is not empty.
                utilisedSize--;                                                                                 // Utilised size decreases by one, as an element is being removed.
                if (utilisedSize <= (size >> 1) && size > 1){                                                   // Checks if the utilised size is now half of the size AND the size is also greater than one.
                    halfSize();
                }
                return elementDereferencing(array[utilisedSize + 1].elementPtr, array[utilisedSize + 1].type);  // Calls upon the function "elementDereferencing" to return a value.  
            }
            return {};                                                                                          // Otherwise, nothing is returned.
        }

        unsigned char getSize(){    // Returns the current size of the array.
            return this->size;
        }

        unsigned char getUtilisedSize(){    // Returns the utilised size of the array.
            return this->utilisedSize;
        }

        std::any getElement(size_t index){                                              // Returns the element of any given index.
            if (index >= utilisedSize || index >= 256){                                 // Checks if the index is greater or equal to the "utilisedSize" OR if the index is equal or greater than 256.
                std::cout << "Out of bounds...";                                        // Out of bounds error, returns nothing.
                return {};
            }
            return elementDereferencing(array[index].elementPtr, array[index].type);    // Uses "elementDereferencing" to return the element.
        }

        void setElement(size_t index, void* element, Datatypes type){                   // Method which inserts an element with a given index.
            if (index >= utilisedSize || index >= 256){                                 // Checks if the index is greater or equal to the "utilisedSize" OR if the index is equal or greater than 256.
                std::cout << "Out of bounds...";                                        // Out of bounds error, returns nothing.
                return;
            }
            array[index].elementPtr = element;                                          // Sets an index within the array equal to the element (void pointer) provided.
            array[index].type = type;                                                   // A type is also provided within the specific index of the array.
        }
};
