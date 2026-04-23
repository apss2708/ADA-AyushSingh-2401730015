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

void selectionSort(vector<int>& arr) {
    stepCount = 0;
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            stepCount++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            stepCount++;
        }
    }
}

int main() {
    vector<int> arr = {35, 12, 48, 7, 22};

    cout << "Original Array:\n";
    printArray(arr);

    selectionSort(arr);

    cout << "Sorted Array (Selection Sort):\n";
    printArray(arr);
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
