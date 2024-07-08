#ifndef DOG_H
#define DOG_H

#include <string>

// Define the Dog struct
struct Dog {
    int id;           // ID of the dog
    std::string name; // Name of the dog
    Dog* next;        // Pointer to the next Dog in the list
};

#endif