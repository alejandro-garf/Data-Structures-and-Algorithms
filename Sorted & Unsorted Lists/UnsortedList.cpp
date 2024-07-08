#include <iostream>
#include "UnsortedList.h"

// Default constructor - Sets the list to an empty list
UnsortedList::UnsortedList() : length(0) {}

// Destructor
UnsortedList::~UnsortedList() {}

// Method to insert an item into the list
void UnsortedList::insertItem(int item) {
    if (!isFull()) { // Check if the list is not full
        numbers[length] = item; // Insert item at the end of the list
        length++; // Increment the length of the list
    } else {
        std::cout << "The list is full – cannot insert the number.\n";
    }
}

// Method to delete an item from the list
void UnsortedList::deleteItem(int item) {
    if (!isEmpty()) { // Check if the list is not empty
        bool found = false; // Flag to check if the item is found
        for (int i = 0; i < length; i++) {
            if (numbers[i] == item) { // Compare each item in the list
                found = true;
                // Shift elements to the left to fill the gap
                for (int j = i; j < length - 1; j++) {
                    numbers[j] = numbers[j + 1];
                }
                length--; // Decrement the length of the list
                std::cout << "Item has been deleted.\n";
                break;
            }
        }
        if (!found) {
            std::cout << "Item is not in the list.\n";
        }
    } else {
        std::cout << "The list is empty.\n";
    }
}

// Method to check if the list is full
bool UnsortedList::isFull() const {
    return length == MAX_SIZE;
}

// Method to check if the list is empty
bool UnsortedList::isEmpty() const {
    return length == 0;
}