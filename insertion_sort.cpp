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

void insertionSort(vector<int>& arr) {
    stepCount = 0;

    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        // Treat arr[i] as the next value to insert into sorted left part.
        int key = arr[i];
        int j = i - 1;

        // Shift larger sorted elements right to create key's position.
        while (j >= 0 && arr[j] > key) {
            stepCount++;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        stepCount++;
    }
}

int main() {
    vector<int> arr = {35, 12, 48, 7, 22};

    cout << "Original Array:\n";
    printArray(arr);

    insertionSort(arr);

    cout << "Sorted Array (Insertion Sort):\n";
    printArray(arr);
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
