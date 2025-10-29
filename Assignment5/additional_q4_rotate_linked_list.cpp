#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Rotate linked list to the left by k positions
    void rotateLeft(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        // Find length of the list
        int length = 1;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        // If k is greater than length, reduce it
        k = k % length;
        if (k == 0) {
            return;
        }

        // Make the list circular
        temp->next = head;

        // Find the new tail (at position k-1) and new head (at position k)
        Node* newTail = head;
        for (int i = 0; i < k - 1; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        head = newHead;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL";
    }
};

int main() {
    LinkedList list;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Enter k (number of rotations to left): ";
    cin >> k;

    cout << "Input: k = " << k << endl;
    cout << "Original List: ";
    list.display();

    list.rotateLeft(k);

    cout << "\nOutput: ";
    list.display();
    cout << endl;

    return 0;
}
