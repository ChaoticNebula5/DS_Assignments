#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    int n = q.size() / 2;
    queue<int> firstHalf;

    // Step 1: Move first half to a temporary queue
    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave elements
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (must be even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "Original Queue: ";
    displayQueue(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    displayQueue(q);

    return 0;
}
