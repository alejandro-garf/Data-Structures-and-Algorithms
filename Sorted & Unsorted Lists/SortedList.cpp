#include <iostream>
#include "SortedList.h"

// Default constructor - Sets the list to an empty list
SortedList::SortedList() : length(0) {}

// Destructor
SortedList::~SortedList() {}

// Method to insert an item into the list using linear search
void SortedList::insertItem(int item) {
    if (!isFull()) { // Check if the list is not full
        int i;
        // Find the correct position to insert the item
        for (i = length - 1; (i >= 0 && numbers[i] > item); i--) {
            numbers[i + 1] = numbers[i]; // Shift elements to the right
        }
        numbers[i + 1] = item; // Insert the item
        length++; // Increment the length of the list
    } else {
        std::cout << "The list is full – cannot insert the number.\n";
    }
}

// Method to delete an item from the list using binary search
void SortedList::deleteItem(int item) {
    if (!isEmpty()) { // Check if the list is not empty
        int low = 0, high = length - 1, mid;
        bool found = false;

        // Binary search for the item
        while (low <= high) {
            mid = (low + high) / 2;
            if (numbers[mid] == item) {
                found = true;
                break;
            } else if (numbers[mid] < item) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (found) {
            // Shift elements to the left to fill the gap
            for (int i = mid; i < length - 1; i++) {
                numbers[i] = numbers[i + 1];
            }
            length--; // Decrement the length of the list
            std::cout << "Item has been deleted.\n";
        } else {
            std::cout << "Item is not in the list.\n";
        }
    } else {
        std::cout << "The list is empty.\n";
    }
}

// Method to check if the list is full
bool SortedList::isFull() const {
    return length == MAX_SIZE;
}

// Method to check if the list is empty
bool SortedList::isEmpty() const {
    return length == 0;
}