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

    // DELETE FROM END
    if (head == NULL) {
        cout << "List is empty! Nothing to delete.";
    }
    else if (head->next == NULL) {
        // Only one node
        delete head;
        head = NULL;
    }
    else {
        temp = head;
        prev = NULL;

        // Traverse to last node
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL; // second last becomes last
        delete temp;       // delete last node
    }

    // Display list
    cout << "\nLinked List after deletion at end: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
