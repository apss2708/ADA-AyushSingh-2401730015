#include <iostream>
#include <vector>

using namespace std;

int stepCount = 0;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int partition(vector<int>& arr, int low, int high) {
    // Lomuto partition: choose last element as pivot.
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        stepCount++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            stepCount++;
        }
    }

    swap(arr[i + 1], arr[high]);
    stepCount++;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        // Recursively sort elements on both sides of pivot.
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {35, 12, 48, 7, 22};

    cout << "Original Array:\n";
    printArray(arr);

    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);

    cout << "Sorted Array (Quick Sort):\n";
    printArray(arr);
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
