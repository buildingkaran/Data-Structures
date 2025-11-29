#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int main() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tree cannot be created!" << endl;
        return 0;
    }

    Node* root = nullptr;
    Node* nodes[100];  // Simple array to store nodes for level-wise insertion
    int index = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (i == 0) {
            root = newNode;  // first node is root
        } else {
            // Level-wise insertion: attach to first available parent
            Node* parent = nodes[index];

            if (parent->left == nullptr) {
                parent->left = newNode;
            } else if (parent->right == nullptr) {
                parent->right = newNode;
                index++; // move to next parent
            }
        }

        nodes[i] = newNode;  // store new node
    }

    // PREORDER TRAVERSAL
    cout << "\nPreorder Traversal: ";
    Node* stack[100];  // simple stack for traversal
    int top = -1;

    if (root != nullptr) {
        top++;
        stack[top] = root;
    }

    while (top >= 0) {
        Node* temp = stack[top];
        top--;

        cout << temp->data << " ";

        // Push right first, then left
        if (temp->right != nullptr) {
            top++;
            stack[top] = temp->right;
        }
        if (temp->left != nullptr) {
            top++;
            stack[top] = temp->left;
        }
    }

    cout << endl;
    return 0;
}
