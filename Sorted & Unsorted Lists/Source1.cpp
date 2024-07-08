// Attached: HW_3(a)
// File: HW_3a.pdf
// =============================================================================
//
// Programmer: Alejandro Fonseca
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Create an array-based UnsortedList data structure
// =============================================================================
// Description:
// creates a list that can hold up to 10 unsorted integers, allowing the user to 
// add or remove numbers. 
// =============================================================================
// =============================================================================

#include <iostream>
#include "UnsortedList.h"

// Function to display the menu
void showMenu() {
    std::cout << "a. Insert a number into the list.\n";
    std::cout << "b. Delete a number from the list.\n";
}

// Function to get the user's choice
char getChoice() {
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main() {
    UnsortedList list; // Declare an unsorted list object
    char choice;

    do {
        showMenu(); // Display the menu
        choice = getChoice(); // Get the user's choice

        if (choice == 'a') {
            int number;
            std::cout << "Enter a number: ";
            std::cin >> number;
            if (!list.isFull()) {
                list.insertItem(number); // Insert the number into the list
            } else {
                std::cout << "The list is full – cannot insert the number.\n";
            }
        } else if (choice == 'b') {
            int number;
            std::cout << "Enter the number to be deleted: ";
            std::cin >> number;
            if (!list.isEmpty()) {
                list.deleteItem(number); // Delete the number from the list
            } else {
                std::cout << "The list is empty.\n";
            }
        }

    } while (choice == 'a' || choice == 'b'); // Continue until the user chooses a different option

    return 0;
}
//OUTPUT
// //a. Insert a number into the list.
// b. Delete a number from the list.
// Enter your choice: a
// Enter a number: 5

// a. Insert a number into the list.
// b. Delete a number from the list.
// Enter your choice: b
// Enter the number to be deleted: 5
// Item has been deleted.

// a. Insert a number into the list.
// b. Delete a number from the list.
// Enter your choice: b
// The list is empty.