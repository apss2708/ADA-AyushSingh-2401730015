#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

double fractionalKnapsack(int capacity, vector<Item> items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return static_cast<double>(a.value) / a.weight > static_cast<double>(b.value) / b.weight;
    });

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity == 0) {
            break;
        }

        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            double fraction = static_cast<double>(capacity) / item.weight;
            totalValue += item.value * fraction;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;

    cout << fixed << setprecision(2);
    cout << "Maximum value (fractional knapsack): " << fractionalKnapsack(capacity, items) << "\n";
    return 0;
}
