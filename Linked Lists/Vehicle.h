#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// Define the Vehicle struct
struct Vehicle {
    int id;            // ID number of the vehicle
    std::string model; // Model of the vehicle
    Vehicle* next;     // Pointer to the next vehicle in the list
};

#endif