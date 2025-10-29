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

    // Create a loop for testing (connects last node to node at position pos)
    void createLoop(int pos) {
        if (head == nullptr || pos < 0) return;

        Node* temp = head;
        Node* loopNode = nullptr;
        int count = 0;

        while (temp->next != nullptr) {
            if (count == pos) {
                loopNode = temp;
            }
            temp = temp->next;
            count++;
        }

        if (loopNode != nullptr) {
            temp->next = loopNode;
        }
    }

    // Detect loop using Floyd's Cycle Detection Algorithm
    bool detectLoop(Node*& loopNode) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                loopNode = slow;
                return true;
            }
        }

        return false;
    }

    // Remove loop if it exists
    void removeLoop() {
        Node* loopNode = nullptr;

        if (!detectLoop(loopNode)) {
            cout << "No loop detected!" << endl;
            return;
        }

        cout << "Loop detected! Removing loop..." << endl;

        // Find the start of the loop
        Node* ptr1 = head;
        Node* ptr2 = loopNode;

        // Special case: loop starts at head
        if (ptr1 == ptr2) {
            while (ptr2->next != ptr1) {
                ptr2 = ptr2->next;
            }
            ptr2->next = nullptr;
            cout << "Loop removed successfully!" << endl;
            return;
        }

        // Move both pointers at same speed to find loop start
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // Remove the loop
        ptr2->next = nullptr;
        cout << "Loop removed successfully!" << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node* temp = head;
        int count = 0;
        cout << "Linked List: ";
        while (temp != nullptr && count < 20) {  // Limit to prevent infinite loop
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
            count++;
        }
        if (count == 20) {
            cout << " ... (loop detected, stopping display)";
        }
        cout << endl;
    }

    void displayAfterRemoval() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List after loop removal: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int n, value, pos;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Enter position to create loop (-1 for no loop): ";
    cin >> pos;

    if (pos >= 0) {
        list.createLoop(pos);
        cout << "Loop created at position " << pos << endl;
    }

    list.removeLoop();
    list.displayAfterRemoval();

    return 0;
}
