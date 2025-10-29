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

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        return count;
    }

    void deleteAllOccurrences(int key) {
        // Delete from beginning
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Delete from middle and end
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty List";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int n, value, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Input: Linked List : ";
    list.display();

    cout << "\nEnter key to search and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Output: Count: " << count;

    list.deleteAllOccurrences(key);
    cout << " , Updated Linked List: ";
    list.display();
    cout << endl;

    return 0;
}
