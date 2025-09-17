#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.
#include <cstring>

bool Stack::isFull(){
    if (utilisedSize >= size){
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if (utilisedSize <= 0){
        return true;
    }
    return false;
}

