#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* temp;
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
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;   // first node
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // INSERTION AT END
    cout << "\nEnter value to insert at end: ";
    cin >> value;

    newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;  // if list was empty
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display Linked List
    cout << "\nLinked List after insertion at end: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
