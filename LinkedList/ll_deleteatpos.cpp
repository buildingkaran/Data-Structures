#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* temp;
    Node* prev;
    Node* newNode;
    int n, value, pos;

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

    // Position to delete
    cout << "\nEnter position to delete: ";
    cin >> pos;

    // DELETE AT GIVEN POSITION
    if (head == NULL) {
        cout << "List is empty!";
    }
    else if (pos == 1) {
        // delete from beginning
        temp = head;
        head = head->next;
        delete temp;
    }
    else {
        temp = head;
        prev = NULL;

        int currentPos = 1;

        // Traverse to position
        while (temp != NULL && currentPos < pos) {
            prev = temp;
            temp = temp->next;
            currentPos++;
        }

        // Invalid position
        if (temp == NULL) {
            cout << "Invalid position!";
        }
        else {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Display list
    cout << "\nLinked List after deletion at position: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
