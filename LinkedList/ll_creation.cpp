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

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        newNode = new Node();   // create new node
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;     // first node
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  // append at end
        }
    }

    // Display linked list
    cout << "\nLinked List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}
