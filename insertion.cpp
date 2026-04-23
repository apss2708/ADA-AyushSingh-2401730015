#include <iostream>
#include <vector>

using namespace std;

// This file mirrors the logic in Insertion.java (which implements linear search).
void linearSearch(const vector<int>& arr, int target) {
    bool isFound = false;

    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == target) {
            cout << "Element found at value: " << arr[i] << "\n";
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        cout << "Element not found in list!\n";
    }
}

int main() {
    vector<int> arr(5);
    cout << "Enter array elements:\n";
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        cin >> arr[i];
    }

    cout << "\nArray elements:\n";
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\nLinear Search\n";

    linearSearch(arr, 20);

    return 0;
}
