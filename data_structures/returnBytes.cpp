/* #include <iostream>
#include "datastructures.h" // Own library created as a header file.

int returnBytes(DATATYPE types){
    switch(types){
        case CHAR:
        case SIGNED_CHAR:
        case UNSIGNED_CHAR:
        case BOOLEAN:
            return sizeof(char);
        
        case SIGNED_SHORT:
        case UNSIGNED_SHORT:
            return sizeof(short);
            
        case SIGNED_INT:
        case UNSIGNED_INT:
            return sizeof(int);
            
        case FLOAT:
            return sizeof(float);
            
        case DOUBLE:
            return sizeof(double);
            
        default:
            return -1;
            break;
    }
}
*/