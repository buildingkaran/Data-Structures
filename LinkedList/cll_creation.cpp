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
    int n, value;

    // Create circular linked list
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            head->next = head;   // Circular link
        } 
        else {
            temp = head;
            while (temp->next != head) {  // Stop before head
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // new node points back to head
        }
    }

    // Display circular linked list
    if (head == NULL) {
        cout << "\nList is empty!";
    } else {
        cout << "\nCircular Linked List: ";
        temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;
    return 0;
}
