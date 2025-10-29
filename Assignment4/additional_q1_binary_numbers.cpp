#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    cout << "Binary numbers from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        string front = q.front();
        cout << front;
        if (i < n) cout << ", ";
        
        q.pop();

        // Generate next binary numbers by appending 0 and 1
        q.push(front + "0");
        q.push(front + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    generateBinaryNumbers(n);

    return 0;
}
