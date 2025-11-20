#include <iostream>
using namespace std;

class heapsort {
public:
    void heapify(int a[], int n, int i) {
        int l = 2*i+1, r = 2*i+2, mx = i;
        if (l < n && a[l] > a[mx]) mx = l;
        if (r < n && a[r] > a[mx]) mx = r;
        if (mx != i) {
            int t = a[i];
            a[i] = a[mx];
            a[mx] = t;
            heapify(a, n, mx);
        }
    }

    void build(int a[], int n) {
        for (int i = n/2-1; i >= 0; i--) heapify(a, n, i);
    }

    void sort_inc(int a[], int n) {
        build(a, n);
        for (int i = n-1; i >= 0; i--) {
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
            heapify(a, i, 0);
        }
    }

    void sort_dec(int a[], int n) {
        sort_inc(a, n);
        for (int i = 0; i < n/2; i++) {
            int t = a[i];
            a[i] = a[n-1-i];
            a[n-1-i] = t;
        }
    }
};

class pq {
public:
    int a[1000];
    int n = 0;

    void heapify(int i) {
        int l = 2*i+1, r = 2*i+2, mx = i;
        if (l < n && a[l] > a[mx]) mx = l;
        if (r < n && a[r] > a[mx]) mx = r;
        if (mx != i) {
            int t = a[i];
            a[i] = a[mx];
            a[mx] = t;
            heapify(mx);
        }
    }

    void insert(int x) {
        a[n] = x;
        int i = n;
        n++;
        while (i > 0) {
            int p = (i-1)/2;
            if (a[p] < a[i]) {
                int t = a[p];
                a[p] = a[i];
                a[i] = t;
                i = p;
            } else break;
        }
    }

    int top() {
        if (n == 0) return -1;
        return a[0];
    }

    void pop() {
        if (n == 0) return;
        a[0] = a[n-1];
        n--;
        heapify(0);
    }

    bool empty() {
        return n == 0;
    }
};

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    heapsort h;
    int a[] = {5,2,8,1,9,3};
    int n = 6;

    h.sort_inc(a, n);
    print(a, n);

    int b[] = {5,2,8,1,9,3};
    h.sort_dec(b, n);
    print(b, n);

    pq q;
    q.insert(5);
    q.insert(2);
    q.insert(9);
    q.insert(1);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
}