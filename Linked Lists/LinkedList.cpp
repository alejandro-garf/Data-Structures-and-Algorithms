#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* Next;
};

void printList(Node*n){
    while (n!=NULL){
        cout << n->value << endl;
        n = n->Next;
    }
}

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
    second->Next = NULL;

    printList(head);


return 0;

};