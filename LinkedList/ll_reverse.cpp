#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* temp;
    Node* newNode;
    Node* prev = NULL;
    Node* current;
    Node* nextNode;
    int n, value;

    // Creating initial linked list
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // REVERSE LINKED LIST
    current = head;

    while (current != NULL) {
        nextNode = current->next;  // Store next
        current->next = prev;      // Reverse pointer
        prev = current;            // Move prev
        current = nextNode;        // Move current
    }

    head = prev; // New head after reverse

    // Display reversed list
    cout << "\nReversed Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
