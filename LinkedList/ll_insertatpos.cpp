#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at specific position
void insertAtPosition(Node* &head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    // If inserting at beginning
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int currentPos = 1;

    // Traverse to position-1
    while(temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    // Invalid position
    if(temp == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // Creating a sample linked list manually
    Node* head = NULL;

    // First node
    head = new Node();
    head->data = 10;
    head->next = NULL;

    // Second node
    Node* second = new Node();
    second->data = 20;
    second->next = NULL;
    head->next = second;

    // Third node
    Node* third = new Node();
    third->data = 40;
    third->next = NULL;
    second->next = third;

    cout << "Initial List: ";
    display(head);

    // Inserting 30 at position 3
    insertAtPosition(head, 30, 3);

    cout << "After inserting 30 at position 3: ";
    display(head);

    return 0;
}
