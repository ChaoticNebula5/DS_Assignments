#include <iostream>
using namespace std;

/*void set(int A[], int n, int i, int j, int x) {
    if (i == j) 
        A[i-1] = x; 
}

int get(int A[], int n, int i, int j) {
    if (i == j) return A[i-1];
    else return 0;
}

void display(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << A[i-1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    int A[4] = {0};  

    set(A, n, 1, 1, 5);
    set(A, n, 2, 2, 8);
    set(A, n, 3, 3, 9);
    set(A, n, 4, 4, 12);

    cout << "Diagonal Matrix:" << endl;
    display(A, n);

    return 0;
}*/



/*void set(int A[], int n, int i, int j, int x) {
    if (i - j == 1)          
        A[i-2] = x;
    else if (i - j == 0)    
        A[n-1 + i-1] = x;
    else if (i - j == -1)   
        A[2*n - 1 + i-1] = x;
}

int get(int A[], int n, int i, int j) {
    if (i - j == 1)          
        return A[i-2];
    else if (i - j == 0)     
        return A[n-1 + i-1];
    else if (i - j == -1)    
        return A[2*n - 1 + i-1];
    else
        return 0;
}

void display(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << get(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    int A[3*4 - 2] = {0};  

    // Setting some values
    set(A, n, 1,1,5);
    set(A, n, 1,2,8);
    set(A, n, 2,1,3);
    set(A, n, 2,2,6);
    set(A, n, 2,3,7);
    set(A, n, 3,2,4);
    set(A, n, 3,3,9);
    set(A, n, 3,4,2);
    set(A, n, 4,3,1);
    set(A, n, 4,4,10);

    cout << "Tri-Diagonal Matrix:" << endl;
    display(A, n);

    return 0;
}*/