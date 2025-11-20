#include <iostream>
using namespace std;

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[m]) m = j;
        }
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int x[1000], y[1000];
    for (int i = 0; i < n1; i++) x[i] = a[l + i];
    for (int j = 0; j < n2; j++) y[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (x[i] <= y[j]) a[k++] = x[i++];
        else a[k++] = y[j++];
    }
    while (i < n1) a[k++] = x[i++];
    while (j < n2) a[k++] = y[j++];
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition_q(int a[], int l, int r) {
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < p) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int p = partition_q(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

void improved_selection_sort(int a[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mn = l, mx = l;
        for (int i = l; i <= r; i++) {
            if (a[i] < a[mn]) mn = i;
            if (a[i] > a[mx]) mx = i;
        }
        int t = a[l];
        a[l] = a[mn];
        a[mn] = t;
        if (mx == l) mx = mn;
        t = a[r];
        a[r] = a[mx];
        a[mx] = t;
        l++;
        r--;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {5, 2, 9, 1, 6, 3};
    int n = 6;

    selection_sort(a, n);
    print(a, n);

    int b[] = {5, 2, 9, 1, 6, 3};
    insertion_sort(b, n);
    print(b, n);

    int c[] = {5, 2, 9, 1, 6, 3};
    bubble_sort(c, n);
    print(c, n);

    int d[] = {5, 2, 9, 1, 6, 3};
    merge_sort(d, 0, n - 1);
    print(d, n);

    int e[] = {5, 2, 9, 1, 6, 3};
    quick_sort(e, 0, n - 1);
    print(e, n);

    int f[] = {5, 2, 9, 1, 6, 3};
    improved_selection_sort(f, n);
    print(f, n);

    return 0;
}