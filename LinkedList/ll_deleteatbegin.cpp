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

    // DELETE FROM BEGINNING
    if (head == NULL) {
        cout << "List is empty! Nothing to delete." << endl;
    } else {
        temp = head;
        head = head->next;  // Move head
        delete temp;        // Delete old head
    }

    // Display list
    cout << "\nLinked List after deletion at beginning: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
