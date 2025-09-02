#include <iostream>
using namespace std;

void findSaddlePoint(int arr[][100], int m, int n) {
    bool found = false;

    for (int i = 0; i < m; i++) {
      
        int minVal = arr[i][0];
        int colIndex = 0;
        for (int j = 1; j < n; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
                colIndex = j;
            }
        }

        bool isSaddle = true;
        for (int k = 0; k < m; k++) {
            if (arr[k][colIndex] > minVal) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            cout << "Saddle point found at (" << i << ", " << colIndex << ") = " << minVal << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No saddle point found." << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int arr[100][100];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    findSaddlePoint(arr, m, n);

    return 0;
}
