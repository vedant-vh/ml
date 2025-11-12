#include <iostream>
using namespace std;

int board[20][20];   // Max board size (can handle up to 20x20 safely)
int solutionCount = 0; // Counter for total solutions

// Function to print one valid board configuration
void printSolution(int n) {
    cout << "\nSolution " << ++solutionCount << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check vertically above
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to place queens row by row
void solveNQueen(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;         // Place queen
            solveNQueen(row + 1, n);     // Recur for next row
            board[row][col] = 0;         // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Please enter a value between 1 and 20." << endl;
        return 0;
    }

    // Initialize board with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    solveNQueen(0, n);

    if (solutionCount == 0)
        cout << "\nNo solution exists for " << n << " queens." << endl;
    else
        cout << "\nTotal number of solutions: " << solutionCount << endl;

    return 0;
}
