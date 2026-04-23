#include <iostream>

using namespace std;

int stepCount = 0;

void fibIterative(int n) {
    stepCount = 0;
    if (n <= 0) {
        cout << "No terms to print.\n";
        return;
    }

    int a = 0;
    int b = 1;
    cout << "Iterative Fibonacci sequence up to " << n << " terms: ";

    if (n >= 1) {
        cout << a << " ";
    }
    if (n >= 2) {
        cout << b << " ";
    }

    for (int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        stepCount++;
    }

    cout << "\nStep Count: " << stepCount << "\n";
}

int fibRecursive(int n) {
    stepCount++;
    if (n <= 1) {
        return n;
    }
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n = 6;
    cout << "Calculating Fibonacci sequence for n = " << n << "\n\n";

    fibIterative(n);

    stepCount = 0;
    cout << "Recursive Fibonacci (N-th term): " << fibRecursive(n - 1) << "\n";
    cout << "Step Count: " << stepCount << "\n";

    return 0;
}
