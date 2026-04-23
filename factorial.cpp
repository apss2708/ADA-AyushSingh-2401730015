#include <iostream>

using namespace std;

int stepCount = 0;

void factIterative(int n) {
    stepCount = 0;
    long long factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        stepCount++;
    }

    cout << "Iterative Factorial of " << n << ": " << factorial << "\n";
    cout << "Step Count: " << stepCount << "\n";
}

long long factRecursive(int n) {
    stepCount++;
    if (n <= 1) {
        return 1;
    }
    return 1LL * n * factRecursive(n - 1);
}

int main() {
    int n = 5;
    cout << "Calculating factorial for n = " << n << "\n\n";

    factIterative(n);

    stepCount = 0;
    long long result = factRecursive(n);
    cout << "Recursive Factorial of " << n << ": " << result << "\n";
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
