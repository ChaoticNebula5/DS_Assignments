#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    int M[10][10], T[10][10];

    cout << "Enter rows and columns of the matrix: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = M[i][j];
        }
    }

    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
