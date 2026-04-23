#include <iostream>

using namespace std;

int stepCount = 0;

void factIterative(int n) {
    stepCount = 0;
    long long factorial = 1;

    // Multiply numbers 1, 2, 3 ... n to build n!.
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        stepCount++;
    }

    cout << "Iterative Factorial of " << n << ": " << factorial << "\n";
    cout << "Step Count: " << stepCount << "\n";
}

long long factRecursive(int n) {
    stepCount++;
    // Base case: 0! and 1! are both 1.
    if (n <= 1) {
        return 1;
    }
    // Recursive definition: n! = n * (n-1)!
    return 1LL * n * factRecursive(n - 1);
}

int main() {
    int n = 5;
    cout << "Calculating factorial for n = " << n << "\n\n";

    // Iterative method uses a loop.
    factIterative(n);

    stepCount = 0;
    // Recursive method calls itself until base case is reached.
    long long result = factRecursive(n);
    cout << "Recursive Factorial of " << n << ": " << result << "\n";
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
