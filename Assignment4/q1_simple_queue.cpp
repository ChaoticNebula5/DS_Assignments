#include <iostream>
using namespace std;

#define MAX_SIZE 100

class SimpleQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    SimpleQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue " << value << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleQueue q;
    int choice, value;

    while (true) {
        cout << "\n--- Simple Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            if (q.isEmpty()) {
                cout << "Queue is Empty" << endl;
            } else {
                cout << "Queue is not Empty" << endl;
            }
        }
        else if (choice == 6) {
            if (q.isFull()) {
                cout << "Queue is Full" << endl;
            } else {
                cout << "Queue is not Full" << endl;
            }
        }
        else if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
