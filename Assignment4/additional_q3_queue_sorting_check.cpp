#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkQueueSorting(queue<int> q) {
    stack<int> s;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        } else {
            // If stack top matches expected, pop from stack
            while (!s.empty() && s.top() == expected) {
                s.pop();
                expected++;
            }

            // If front is greater than stack top, it can't be sorted
            if (!s.empty() && s.top() < front) {
                return false;
            }

            s.push(front);
        }
    }

    // Check remaining stack elements
    while (!s.empty()) {
        if (s.top() != expected) {
            return false;
        }
        s.pop();
        expected++;
    }

    return true;
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

    cout << "Input: Queue[] = { ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
        if (!temp.empty()) cout << ", ";
    }
    cout << " }" << endl;

    if (checkQueueSorting(q)) {
        cout << "Output: Yes" << endl;
    } else {
        cout << "Output: No" << endl;
    }

    return 0;
}
