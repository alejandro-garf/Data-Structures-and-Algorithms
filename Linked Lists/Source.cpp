// Attached: HW_4-2
// File: HW_4-2.pdf
// =============================================================================
//
// Programmer: Alejandro Fonseca
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: LinkedList
// =============================================================================
// Description:
// creates a linked list of vehicle objects, where each vehicle has an ID number 
// and a model name. It allows the user to add vehicles to the list, display the entire list, and search for a specific vehicle by its ID. 
// =============================================================================
// =============================================================================

#include <iostream>
#include <string>
#include "Vehicle.h"

// Function prototypes
void insertVehicle(Vehicle*& head);
void displayVehicles(Vehicle* head);
void searchList(Vehicle* head, int id);

int main() {
    Vehicle* head = nullptr; // Start with an empty list (head is null)
    char anotherVehicle;     // Variable to store the user's choice to enter another vehicle or not

    // Loop to create a linked list of at least 5 vehicles
    for (int i = 0; i < 5; ++i) {
        insertVehicle(head); // Call the function to insert the vehicle into the list
        if (i < 4) { // Only prompt for additional vehicles if not yet inserted 5
            std::cout << "Enter another vehicle (Y or N)? ";
            std::cin >> anotherVehicle;
            if (anotherVehicle != 'Y' && anotherVehicle != 'y') {
                break; // Exit the loop if the user does not want to enter another vehicle
            }
        }
    }

    // Clear the screen
    system("clear"); // Use "cls" on Windows

    // Ask the user if they want to display the list
    char displayChoice;
    std::cout << "Display the list (Y/N)? ";
    std::cin >> displayChoice;
    if (displayChoice == 'Y' || displayChoice == 'y') {
        // Clear the screen again before displaying the list
        system("clear"); // Use "cls" on Windows
        displayVehicles(head); // Call the function to display the list
    }

    // Clear the screen
    system("clear"); // Use "cls" on Windows

    // Prompt the user for the ID of the vehicle to be searched
    int searchId;
    std::cout << "Enter the ID of a vehicle to be found: ";
    std::cin >> searchId;
    searchList(head, searchId); // Call the function to search for the vehicle

    return 0;
}

// Function to insert a new vehicle into the list
void insertVehicle(Vehicle*& head) {
    // Create a new Vehicle object
    Vehicle* newVehicle = new Vehicle;
    
    // Ask the user to enter the vehicle's ID
    std::cout << "ID: ";
    std::cin >> newVehicle->id;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    // Ask the user to enter the vehicle's model
    std::cout << "Model: ";
    std::getline(std::cin, newVehicle->model);

    // Make the new vehicle point to the current head of the list
    newVehicle->next = head;

    // Update the head to point to the new vehicle
    head = newVehicle;
}

// Function to display the list of vehicles
void displayVehicles(Vehicle* head) {
    std::cout << "Here is the list:\n";
    Vehicle* current = head; // Start from the head of the list
    while (current != nullptr) { // Loop until the end of the list
        std::cout << "ID: " << current->id << "\n"; // Print the ID of the current vehicle
        std::cout << "Model: " << current->model << "\n"; // Print the model of the current vehicle
        current = current->next; // Move to the next vehicle in the list
    }
}

// Function to search for a vehicle by ID
void searchList(Vehicle* head, int id) {
    Vehicle* current = head; // Start from the head of the list
    while (current != nullptr) { // Loop until the end of the list
        if (current->id == id) { // If the ID matches
            std::cout << "We found the vehicle!\n";
            std::cout << "ID: " << current->id << "\n"; // Print the ID of the found vehicle
            std::cout << "Model: " << current->model << "\n"; // Print the model of the found vehicle
            return;
        }
        current = current->next; // Move to the next vehicle in the list
    }
    std::cout << id << " is not in the list.\n"; // If the ID is not found
}

// ===========================================================================
// OUTPUT
// Enter ID: 100
// Model: Jeep
// Enter another vehicle (Y or N)? y
// Enter ID: 101
// Model: Toyota
// Enter another vehicle (Y or N)? y
// Enter ID: 102
// Model: Honda
// Enter another vehicle (Y or N)? y
// Enter ID: 103
// Model: Ford
// Enter another vehicle (Y or N)? y
// Enter ID: 104
// Model: Fiat
// Enter another vehicle (Y or N)? n
// Display the list (Y/N)? y
// Here is the list:
// ID: 104
// Model: Fiat
// ID: 103
// Model: Ford
// ID: 102
// Model: Honda
// ID: 101
// Model: Toyota
// ID: 100
// Model: Jeep
// Enter the ID of a vehicle to be found: 104
// We found the vehicle!
// ID: 104
// Model: Fiat