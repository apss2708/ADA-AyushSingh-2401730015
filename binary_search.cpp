#include <iostream>
#include <vector>

using namespace std;

int stepCount = 0;

int binarySearchIterative(const vector<int>& arr, int key) {
    stepCount = 0;
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        stepCount++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(const vector<int>& arr, int low, int high, int key) {
    stepCount++;
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] < key) {
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    vector<int> arr = {7, 12, 22, 35, 48};
    int key = 22;

    cout << "Searching for key: " << key << " in sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";

    int result1 = binarySearchIterative(arr, key);
    if (result1 != -1) {
        cout << "Iterative: Element found at index " << result1 << "\n";
    } else {
        cout << "Iterative: Element not found\n";
    }
    cout << "Step Count (Iterative): " << stepCount << "\n";

    stepCount = 0;
    int result2 = binarySearchRecursive(arr, 0, static_cast<int>(arr.size()) - 1, key);
    if (result2 != -1) {
        cout << "Recursive: Element found at index " << result2 << "\n";
    } else {
        cout << "Recursive: Element not found\n";
    }
    cout << "Step Count (Recursive): " << stepCount << "\n";

    return 0;
}
