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

    // Reverse k nodes at a time
    void reverseKGroup(int k) {
        head = reverseKGroupHelper(head, k);
    }

private:
    Node* reverseKGroupHelper(Node* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        // Check if there are at least k nodes left
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        // If there are at least k nodes, reverse them
        if (count == k) {
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;
            count = 0;

            // Reverse k nodes
            while (current != nullptr && count < k) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            // Recursively reverse the remaining list
            if (next != nullptr) {
                head->next = reverseKGroupHelper(next, k);
            }

            return prev;
        }

        // If less than k nodes, return head as is
        return head;
    }

public:
    void display() {
        if (head == nullptr) {
            cout << "Empty";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "→";
            }
            temp = temp->next;
        }
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

    cout << "Enter K: ";
    cin >> k;

    cout << "Input: Linked list: ";
    list.display();
    cout << " , K: " << k << endl;

    list.reverseKGroup(k);

    cout << "Output: Result: ";
    list.display();
    cout << endl;

    return 0;
}
