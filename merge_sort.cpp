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

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge two sorted halves into the original array.
    while (i < n1 && j < n2) {
        stepCount++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Split, sort both halves, then merge.
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {35, 12, 48, 7, 22};

    cout << "Original Array:\n";
    printArray(arr);

    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    cout << "Sorted Array (Merge Sort):\n";
    printArray(arr);
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
