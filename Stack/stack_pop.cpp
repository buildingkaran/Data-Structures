#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, value;

    cout << "Enter number of elements to push initially: ";
    cin >> n;

    // Push elements into stack
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        if (top >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            break;
        }

        top++;
        stack[top] = value;
    }

    // Pop operation
    if (top < 0) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        value = stack[top];
        top--;
        cout << "\nPopped element: " << value << endl;
    }

    // Display stack elements
    cout << "\nCurrent Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    cout << endl;
    return 0;
}
