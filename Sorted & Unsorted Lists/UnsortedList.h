#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

// Maximum number of items in the list
const int MAX_SIZE = 10;

class UnsortedList {
private:
    int numbers[MAX_SIZE]; // Array to hold the integer values
    int length;            // Variable to keep track of the length of the list

public:
    UnsortedList();        // Default constructor
    ~UnsortedList();       // Destructor
    void insertItem(int item); // Method to insert an item into the list
    void deleteItem(int item); // Method to delete an item from the list
    bool isFull() const;       // Method to check if the list is full
    bool isEmpty() const;      // Method to check if the list is empty
};

#endif // UNSORTEDLIST_H