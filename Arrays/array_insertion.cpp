#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter the value to insert: ";
    cin >> value;

    cout << "Enter the position (0 to " << n << "): ";
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!";
        return 0;
    }

    // Shifting elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value; // Insert the new element
    n++; // Increase size

    cout << "\nArray after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
