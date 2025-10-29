#include <iostream>
#include <queue>
using namespace std;

void sortQueue(queue<int>& q) {
    if (q.empty()) return;

    int n = q.size();
    
    // Bubble sort approach
    for (int i = 0; i < n; i++) {
        int minIndex = -1;
        int minVal = INT_MAX;
        int size = q.size();

        // Find minimum element in current pass
        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            if (curr < minVal && j < (size - i)) {
                minIndex = j;
                minVal = curr;
            }
            q.push(curr);
        }

        // Place minimum at correct position
        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            if (j != minIndex) {
                q.push(curr);
            }
        }
        q.push(minVal);
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "Input: ";
    displayQueue(q);

    sortQueue(q);

    cout << "Output: ";
    displayQueue(q);

    return 0;
}
