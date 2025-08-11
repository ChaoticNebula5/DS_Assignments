#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int arr[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int sumRow = 0;
        for (int j = 0; j < cols; j++) {
            sumRow += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sumRow << "\n";
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int sumCol = 0;
        for (int i = 0; i < rows; i++) {
            sumCol += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << sumCol << "\n";
    }

    return 0;
}
