#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* Next;
};

int main()
{
    Node* head = new Node();
    Node* first = new Node();
    Node* second = new Node();

    head->value = 1;
    head->Next = first;
    first->value = 2;
    first->Next = second;
    second->value = 3;


return 0;

};