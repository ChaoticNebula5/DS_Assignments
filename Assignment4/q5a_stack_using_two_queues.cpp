#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int value) {
        // Push to q2
        q2.push(value);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack using Two Queues ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.top();
        }
        else if (choice == 4) {
            s.display();
        }
        else if (choice == 5) {
            if (s.isEmpty()) {
                cout << "Stack is Empty" << endl;
            } else {
                cout << "Stack is not Empty" << endl;
            }
        }
        else if (choice == 6) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
