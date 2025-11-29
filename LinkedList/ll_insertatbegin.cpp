#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* newNode;
    int n, value;

    // Creating initial linked list
    cout << "Enter number of initial nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insertion at beginning
    cout << "\nEnter value to insert at beginning: ";
    cin >> value;

    newNode = new Node();
    newNode->data = value;
    newNode->next = head;  // link new node to previous head
    head = newNode;        // update head

    // Display linked list
    cout << "\nLinked List after insertion at beginning: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
