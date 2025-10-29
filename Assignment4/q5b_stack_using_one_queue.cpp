#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int value) {
        int size = q.size();
        
        // Add the new element
        q.push(value);

        // Rotate the queue to make the new element at front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack using One Queue ---" << endl;
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
