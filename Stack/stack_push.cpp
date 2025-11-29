#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, value;

    cout << "Enter number of elements to push: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        // Check for stack overflow
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push more elements." << endl;
            break;
        }

        top++;
        stack[top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Display stack elements
    cout << "\nCurrent Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    cout << endl;
    return 0;
}
