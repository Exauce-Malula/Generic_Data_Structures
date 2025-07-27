#pragma once

typedef struct LinkedList LinkedList;
typedef LinkedList* ll_ptr;
ll_ptr initLinkedList;

typedef enum DATATYPE{// Enum to signify what data type the structure will contain.
    SIGNED_INT,       // 0, 4 bytes
    UNSIGNED_INT,     // 1, 4 bytes
    CHAR,             // 2, 1 byte
    SIGNED_CHAR,      // 3, 1 byte
    UNSIGNED_CHAR,    // 4, 1 byte
    SIGNED_SHORT,     // 5, 2 bytes
    UNSIGNED_SHORT,   // 6, 2 bytes
    STRING,           // 7, Dynamic
    CPP_STYLE_STRING, // 8, Dynamic
    BOOLEAN,          // 9, 1 byte
    FLOAT,            // 10, 4 bytes
    DOUBLE            // 11, 8 bytes
}DATATYPE;

enum class Datatypes{    // An enumeration class containing data types, for dereferencing pointers.
    SIGNED_INT,         // 0, 4 bytes
    UNSIGNED_INT,       // 1, 4 bytes
    UNSIGNED_LONG_INT,  // 2, 8 bytes
    CHAR,               // 3, 1 byte
    SIGNED_CHAR,        // 4, 1 byte
    UNSIGNED_CHAR,      // 5, 1 byte
    SIGNED_SHORT,       // 6, 2 bytes
    UNSIGNED_SHORT,     // 7, 2 bytes
    STRING,             // 8, Dynamic
    BOOLEAN,            // 9, 1 byte
    FLOAT,              // 10, 4 bytes
    DOUBLE              // 11, 8 bytes
};

typedef enum STRUCTURE{ // Enum to signify the type of structure.
    LINKEDLIST,         // 0
    STACK,              // 1
    QUEUE,              // 2
    PRIORITY_QUEUE,     // 3
    BINARY_TREE,        // 4
    BINARY_SEARCH_TREE, // 5
    DYNAMIC_ARRAY       // 6
}STRUCTURE;

bool null_check(void* dynamicallyAllocatedMemory);
bool nullptr_check(void* dynamicallyAllocatedMemory);
int returnBytes(DATATYPE types);
