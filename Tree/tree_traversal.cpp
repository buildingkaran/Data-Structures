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
    Node* nodes[100];  // array to store nodes for level-wise insertion
    int index = 0;

    // Creating tree level-wise
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
            Node* parent = nodes[index];
            if (parent->left == nullptr) {
                parent->left = newNode;
            } else if (parent->right == nullptr) {
                parent->right = newNode;
                index++;
            }
        }

        nodes[i] = newNode;
    }

    // INORDER TRAVERSAL (Left → Root → Right)
    cout << "\nInorder Traversal: ";
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != nullptr || top >= 0) {
        while (current != nullptr) {
            top++;
            stack[top] = current;
            current = current->left;
        }
        current = stack[top];
        top--;
        cout << current->data << " ";
        current = current->right;
    }

    // POSTORDER TRAVERSAL (Left → Right → Root)
    cout << "\nPostorder Traversal: ";
    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    if (root != nullptr) {
        top1++;
        stack1[top1] = root;
    }

    while (top1 >= 0) {
        Node* temp = stack1[top1];
        top1--;
        top2++;
        stack2[top2] = temp;

        if (temp->left != nullptr) {
            top1++;
            stack1[top1] = temp->left;
        }
        if (temp->right != nullptr) {
            top1++;
            stack1[top1] = temp->right;
        }
    }

    while (top2 >= 0) {
        cout << stack2[top2]->data << " ";
        top2--;
    }

    cout << endl;
    return 0;
}
