#include <iostream>
#include <vector>

using namespace std;

void linearSearch(const vector<int>& arr, int target) {
    bool isFound = false;

    // Check each element sequentially until target is found.
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << " with value: " << arr[i] << "\n";
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        // This runs only if the loop never found target.
        cout << "Element not found in list!\n";
    }
}

int main() {
    vector<int> arr(5);
    cout << "Enter 5 array elements:\n";
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        cin >> arr[i];
    }

    cout << "\nArray elements:\n";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << "\n";

    cout << "\nLinear Search for target: 20\n";
    // Search for a fixed target value from the original assignment.
    linearSearch(arr, 20);

    return 0;
}
