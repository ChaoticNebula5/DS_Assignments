#include <iostream>
#include <unordered_set>
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
public:
    Node* head;

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

    void display() {
        if (head == nullptr) {
            cout << "Empty";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ",";
            }
            temp = temp->next;
        }
    }

    // Method 1: Using Hash Set
    static Node* findIntersectionUsingSet(Node* headA, Node* headB) {
        unordered_set<Node*> nodes;
        
        Node* temp = headA;
        while (temp != nullptr) {
            nodes.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr) {
            if (nodes.find(temp) != nodes.end()) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    // Method 2: Two Pointer Approach (Optimal)
    static Node* findIntersection(Node* headA, Node* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        Node* ptrA = headA;
        Node* ptrB = headB;

        // When one pointer reaches end, redirect it to other list's head
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        return ptrA;
    }

    // Helper function to create intersection
    static void createIntersection(LinkedList& listA, LinkedList& listB, int intersectVal) {
        Node* tempA = listA.head;
        Node* tempB = listB.head;

        // Find node with intersectVal in listA
        while (tempA != nullptr && tempA->data != intersectVal) {
            tempA = tempA->next;
        }

        if (tempA == nullptr) return;

        // Find last node in listB before intersection
        while (tempB->next != nullptr) {
            tempB = tempB->next;
        }

        // Create intersection
        tempB->next = tempA;
    }
};

int main() {
    LinkedList listA, listB;
    int nA, nB, value, intersectVal;

    cout << "Enter number of elements in list A: ";
    cin >> nA;
    cout << "Enter elements for list A: ";
    for (int i = 0; i < nA; i++) {
        cin >> value;
        listA.insertAtEnd(value);
    }

    cout << "Enter number of elements in list B (before intersection): ";
    cin >> nB;
    cout << "Enter elements for list B: ";
    for (int i = 0; i < nB; i++) {
        cin >> value;
        listB.insertAtEnd(value);
    }

    cout << "Enter intersection node value (or -1 for no intersection): ";
    cin >> intersectVal;

    if (intersectVal != -1) {
        LinkedList::createIntersection(listA, listB, intersectVal);
    }

    cout << "Input: listA = [";
    listA.display();
    cout << "], listB = [";
    listB.display();
    cout << "]" << endl;

    Node* intersection = LinkedList::findIntersection(listA.head, listB.head);
    
    if (intersection != nullptr) {
        cout << "Output: Intersected at " << intersection->data << endl;
    } else {
        cout << "Output: No intersection" << endl;
    }

    return 0;
}
