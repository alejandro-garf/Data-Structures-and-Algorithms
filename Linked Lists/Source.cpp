// Attached: HW_4-1(ab)
// File: HW_4-1ab.pdf
// =============================================================================
//
// Programmer: Alejandro Fonseca
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Write a program that creates a linked list of Dogs
// =============================================================================
// Description:
// creates a linked list of dogs, allowing the user to add dogs by 
// entering their ID and name, display the current list, and delete a dog by its ID. 
// =============================================================================
// =============================================================================

#include <iostream>
#include <string>
#include "Dog.h"

// Function prototypes
void insertDog(Dog*& head, int id, const std::string& name);
void displayList(Dog* head);
void deleteDog(Dog*& head, int id);

int main() {
    Dog* head = nullptr; // Start with an empty list (head is null)
    int id; // Variable to store the ID of the dog
    std::string name; // Variable to store the name of the dog
    char anotherDog; // Variable to store the user's choice to enter another dog or not
    
    // Loop to create a linked list of at least 3 dogs
    while (true) {
        // Ask the user to enter the dog's ID
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cin.ignore(); // Ignore the newline character left in the input buffer
        
        // Ask the user to enter the dog's name
        std::cout << "Name: ";
        std::getline(std::cin, name);
        
        // Call the function to insert the dog into the list
        insertDog(head, id, name);
        
        // Ask the user if they want to enter another dog
        std::cout << "Enter another dog (Y or N)? ";
        std::cin >> anotherDog;
        if (anotherDog != 'Y' && anotherDog != 'y') {
            break; // Exit the loop if the user does not want to enter another dog
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
        displayList(head); // Call the function to display the list
    }

    // Ask the user for the ID of the dog to be deleted
    std::cout << "Enter an ID of a dog to be deleted: ";
    std::cin >> id;
    deleteDog(head, id); // Call the function to delete the dog

    return 0;
}

// Function to insert a new dog into the list
void insertDog(Dog*& head, int id, const std::string& name) {
    // Create a new Dog object
    Dog* newDog = new Dog;
    newDog->id = id; // Set the ID of the new dog
    newDog->name = name; // Set the name of the new dog
    
    // Make the new dog point to the current head of the list
    newDog->next = head;
    
    // Update the head to point to the new dog
    head = newDog;
}

// Function to display the list of dogs
void displayList(Dog* head) {
    std::cout << "Here is the list:\n";
    Dog* current = head; // Start from the head of the list
    while (current != nullptr) { // Loop until the end of the list
        std::cout << "ID: " << current->id << "\n"; // Print the ID of the current dog
        std::cout << "Name: " << current->name << "\n"; // Print the name of the current dog
        current = current->next; // Move to the next dog in the list
    }
}

// Function to delete a dog from the list
void deleteDog(Dog*& head, int id) {
    Dog* current = head; // Start from the head of the list
    Dog* previous = nullptr; // To keep track of the previous node
    
    // Loop to find the dog with the given ID
    while (current != nullptr && current->id != id) {
        previous = current; // Move the previous pointer to the current dog
        current = current->next; // Move the current pointer to the next dog
    }
    
    if (current == nullptr) {
        // If the ID is not found in the list
        std::cout << id << " is not in the list.\n";
    } else {
        // If the ID is found, remove the dog from the list
        if (previous == nullptr) {
            head = head->next; // Update the head if the dog to be deleted is the first dog
        } else {
            previous->next = current->next; // Bypass the current dog
        }
        delete current; // Free the memory of the deleted dog
        std::cout << "The dog has been deleted.\n";
    }
    
    // Display the list after deletion
    std::cout << "Here is the list after the delete:\n";
    displayList(head);
}


// OUTPUT
// Enter ID: 100
// Name: Bud
// Enter another dog (Y or N)? Y
// Enter ID: 101
// Name: Big Boy
// Enter another dog (Y or N)? Y
// Enter ID: 102
// Name: Spot
// Enter another dog (Y or N)? Y
// Enter ID: 103
// Name: Red
// Enter another dog (Y or N)? N
// Display the list (Y/N)? Y
// Here is the list:
// ID: 103
// Name: Red
// ID: 102
// Name: Spot
// ID: 101
// Name: Big Boy
// ID: 100
// Name: Bud
// Enter an ID of a dog to be deleted: 101
// The dog has been deleted.
// Here is the list after the delete:
// ID: 103
// Name: Red
// ID: 102
// Name: Spot
// ID: 100
// Name: Bud