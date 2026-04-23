#include <iostream>
#include <vector>

using namespace std;

void backtrack(const vector<int>& arr,
               int target,
               int idx,
               int currentSum,
               vector<int>& subset,
               vector<vector<int>>& allSubsets) {
    if (currentSum == target) {
        allSubsets.push_back(subset);
        return;
    }

    if (idx >= static_cast<int>(arr.size()) || currentSum > target) {
        return;
    }

    // Include current element.
    subset.push_back(arr[idx]);
    backtrack(arr, target, idx + 1, currentSum + arr[idx], subset, allSubsets);
    subset.pop_back();

    // Exclude current element.
    backtrack(arr, target, idx + 1, currentSum, subset, allSubsets);
}

int main() {
    vector<int> arr = {3, 4, 5, 2};
    int target = 7;

    vector<int> subset;
    vector<vector<int>> allSubsets;
    backtrack(arr, target, 0, 0, subset, allSubsets);

    if (allSubsets.empty()) {
        cout << "No subsets found for target " << target << "\n";
    } else {
        cout << "Subsets with sum " << target << ":\n";
        for (const auto& s : allSubsets) {
            cout << "{ ";
            for (int x : s) {
                cout << x << " ";
            }
            cout << "}\n";
        }
    }

    return 0;
}
