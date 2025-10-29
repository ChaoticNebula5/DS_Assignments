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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning" << endl;
    }

    // (b) Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " at the end" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at the end" << endl;
    }

    // (c) Insertion before a specific node
    void insertBefore(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " before " << target << endl;
    }

    // (c) Insertion after a specific node
    void insertAfter(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << target << endl;
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning" << endl;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end" << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from the end" << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node with value " << value << " not found!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted node with value " << value << endl;
        delete nodeToDelete;
    }

    // (g) Search for a node and display its position
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        int position = 0;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << " from head" << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Node with value " << value << " not found!" << endl;
    }

    // (h) Display all the node values
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
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
    SinglyLinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Node" << endl;
        cout << "4. Insert After a Node" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete a Specific Node" << endl;
        cout << "8. Search for a Node" << endl;
        cout << "9. Display List" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
        }
        else if (choice == 2) {
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
        }
        else if (choice == 3) {
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter target node value: ";
            cin >> target;
            list.insertBefore(value, target);
        }
        else if (choice == 4) {
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter target node value: ";
            cin >> target;
            list.insertAfter(value, target);
        }
        else if (choice == 5) {
            list.deleteFromBeginning();
        }
        else if (choice == 6) {
            list.deleteFromEnd();
        }
        else if (choice == 7) {
            cout << "Enter value of node to delete: ";
            cin >> value;
            list.deleteNode(value);
        }
        else if (choice == 8) {
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
        }
        else if (choice == 9) {
            list.display();
        }
        else if (choice == 10) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
