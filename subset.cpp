#include <iostream>
#include <vector>
using namespace std;

int totalSolutions = 0;  // Count of valid subsets

// Function to print a valid subset
void display(const vector<int>& w, const vector<int>& x, int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            cout << w[i] << " ";
    }
    cout << "}\n";
}

// Recursive backtracking function
void subsetSum(const vector<int>& w, vector<int>& x, int n, int M, int i, int sum) {
    if (sum == M) {
        totalSolutions++;
        display(w, x, n);
        return;
    }

    if (i >= n || sum > M)
        return;

    // Include current element
    x[i] = 1;
    subsetSum(w, x, n, M, i + 1, sum + w[i]);

    // Exclude current element
    x[i] = 0;
    subsetSum(w, x, n, M, i + 1, sum);
}

int main() {
    int n, M;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> w(n);  // elements
    vector<int> x(n, 0); // solution vector initialized to 0

    cout << "Enter elements of the set:\n";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter target sum (M): ";
    cin >> M;

    cout << "\nSubsets with sum = " << M << " are:\n";
    subsetSum(w, x, n, M, 0, 0);

    if (totalSolutions == 0)
        cout << "\nNo subset found.\n";
    else
        cout << "\nTotal subsets found: " << totalSolutions << endl;

    return 0;
}
