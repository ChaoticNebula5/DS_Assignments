#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

void printSparseMatrix(Element triplets[], int size) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < size; i++) {
        cout << triplets[i].row << "\t" << triplets[i].col << "\t" << triplets[i].value << "\n";
    }
}

void transpose(Element triplets[], int size, Element transposed[]) {
    for (int i = 0; i < size; i++) {
        transposed[i].row = triplets[i].col;
        transposed[i].col = triplets[i].row;
        transposed[i].value = triplets[i].value;
    }
}

int add(Element A[], int sizeA, Element B[], int sizeB, Element result[]) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[k++] = B[j++];
        } else {
            int sum = A[i].value + B[j].value;
            if (sum != 0) {
                result[k].row = A[i].row;
                result[k].col = A[i].col;
                result[k].value = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i < sizeA) result[k++] = A[i++];
    while (j < sizeB) result[k++] = B[j++];

    return k; 
}

int multiply(Element A[], int sizeA, int m, int n,
             Element B[], int sizeB, int p,
             Element result[]) {

    int k = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i].col == B[j].row) {
                bool found = false;
                for (int r = 0; r < k; r++) {
                    if (result[r].row == A[i].row && result[r].col == B[j].col) {
                        result[r].value += A[i].value * B[j].value;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[k].row = A[i].row;
                    result[k].col = B[j].col;
                    result[k].value = A[i].value * B[j].value;
                    k++;
                }
            }
        }
    }

    int newSize = 0;
    for (int i = 0; i < k; i++) {
        if (result[i].value != 0) {
            result[newSize++] = result[i];
        }
    }

    return newSize;
}

int main() {
    Element A[] = { {0, 2, 5}, {1, 1, 8}, {2, 0, 3} };
    int sizeA = 3;

    Element B[] = { {0, 1, 2}, {1, 1, 7}, {2, 0, 1} };
    int sizeB = 3;

    cout << "Matrix A:\n";
    printSparseMatrix(A, sizeA);

    cout << "\nMatrix B:\n";
    printSparseMatrix(B, sizeB);

    Element At[sizeA];
    transpose(A, sizeA, At);
    cout << "\nTranspose of A:\n";
    printSparseMatrix(At, sizeA);

    Element C[sizeA + sizeB];  
    int sizeC = add(A, sizeA, B, sizeB, C);
    cout << "\nA + B:\n";
    printSparseMatrix(C, sizeC);

    Element D[sizeA * sizeB];  
    int sizeD = multiply(A, sizeA, 3, 3, B, sizeB, 3, D);
    cout << "\nA * B:\n";
    printSparseMatrix(D, sizeD);

    return 0;
}
