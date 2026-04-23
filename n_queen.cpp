#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& pos, int row, int col) {
    // Check conflicts with previously placed queens.
    for (int i = 0; i < row; i++) {
        if (pos[i] == col || abs(pos[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueen(int n, int row, vector<int>& pos) {
    if (row == n) {
        return true;
    }

    // Try every column for the current row.
    for (int col = 0; col < n; col++) {
        if (isSafe(pos, row, col)) {
            pos[row] = col;
            if (solveNQueen(n, row + 1, pos)) {
                return true;
            }
        }
    }

    return false;
}

void printBoard(int n, const vector<int>& pos) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (pos[i] == j ? "Q " : ". ");
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;
    vector<int> pos(n, -1);

    if (solveNQueen(n, 0, pos)) {
        cout << "One valid arrangement for " << n << "-Queen:\n";
        printBoard(n, pos);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
