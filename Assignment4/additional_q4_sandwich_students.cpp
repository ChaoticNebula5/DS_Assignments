#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    stack<int> sandwichStack;

    // Initialize queue with students
    for (int i = 0; i < students.size(); i++) {
        studentQueue.push(students[i]);
    }

    // Initialize stack with sandwiches (reverse order for stack)
    for (int i = sandwiches.size() - 1; i >= 0; i--) {
        sandwichStack.push(sandwiches[i]);
    }

    int rotations = 0;
    int queueSize = studentQueue.size();

    while (!studentQueue.empty() && rotations < queueSize) {
        if (studentQueue.front() == sandwichStack.top()) {
            // Student takes sandwich
            studentQueue.pop();
            sandwichStack.pop();
            rotations = 0;
            queueSize = studentQueue.size();
        } else {
            // Student goes to back of queue
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            rotations++;
        }
    }

    return studentQueue.size();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> students(n);
    vector<int> sandwiches(n);

    cout << "Enter student preferences (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << "Enter sandwich types (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    cout << "Input: students = [";
    for (int i = 0; i < n; i++) {
        cout << students[i];
        if (i < n - 1) cout << ",";
    }
    cout << "], sandwiches = [";
    for (int i = 0; i < n; i++) {
        cout << sandwiches[i];
        if (i < n - 1) cout << ",";
    }
    cout << "]" << endl;

    int result = countStudents(students, sandwiches);
    cout << "Output: " << result << endl;

    return 0;
}
