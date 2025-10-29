#include <iostream>
using namespace std;

struct Node {
    int coeff;   // Coefficient
    int power;   // Power of variable
    Node* next;
    
    Node(int c, int p) {
        coeff = c;
        power = p;
        next = nullptr;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    // Insert term in descending order of power
    void insertTerm(int coeff, int power) {
        Node* newNode = new Node(coeff, power);
        
        if (head == nullptr || head->power < power) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->power > power) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Add two polynomials
    static Polynomial addPolynomials(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* ptr1 = p1.head;
        Node* ptr2 = p2.head;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->power == ptr2->power) {
                int sumCoeff = ptr1->coeff + ptr2->coeff;
                if (sumCoeff != 0) {
                    result.insertTerm(sumCoeff, ptr1->power);
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->power > ptr2->power) {
                result.insertTerm(ptr1->coeff, ptr1->power);
                ptr1 = ptr1->next;
            }
            else {
                result.insertTerm(ptr2->coeff, ptr2->power);
                ptr2 = ptr2->next;
            }
        }

        // Add remaining terms from p1
        while (ptr1 != nullptr) {
            result.insertTerm(ptr1->coeff, ptr1->power);
            ptr1 = ptr1->next;
        }

        // Add remaining terms from p2
        while (ptr2 != nullptr) {
            result.insertTerm(ptr2->coeff, ptr2->power);
            ptr2 = ptr2->next;
        }

        return result;
    }

    void display() {
        if (head == nullptr) {
            cout << "0";
            return;
        }

        Node* temp = head;
        bool first = true;
        while (temp != nullptr) {
            if (!first && temp->coeff > 0) {
                cout << " + ";
            } else if (temp->coeff < 0) {
                cout << " - ";
                temp->coeff = -temp->coeff;
            }

            if (temp->power == 0) {
                cout << temp->coeff;
            } else if (temp->power == 1) {
                if (temp->coeff == 1) {
                    cout << "x";
                } else {
                    cout << temp->coeff << "x";
                }
            } else {
                if (temp->coeff == 1) {
                    cout << "x^" << temp->power;
                } else {
                    cout << temp->coeff << "x^" << temp->power;
                }
            }

            first = false;
            temp = temp->next;
        }
    }

    void displayAsArray() {
        if (head == nullptr) {
            cout << "[]";
            return;
        }

        cout << "[";
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->coeff << ", " << temp->power << "]";
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "]";
    }
};

int main() {
    Polynomial p1, p2;
    int n1, n2, coeff, power;

    cout << "Enter number of terms in polynomial 1: ";
    cin >> n1;
    cout << "Enter terms (coefficient and power):\n";
    for (int i = 0; i < n1; i++) {
        cout << "Term " << (i+1) << " - Coefficient: ";
        cin >> coeff;
        cout << "Term " << (i+1) << " - Power: ";
        cin >> power;
        p1.insertTerm(coeff, power);
    }

    cout << "\nEnter number of terms in polynomial 2: ";
    cin >> n2;
    cout << "Enter terms (coefficient and power):\n";
    for (int i = 0; i < n2; i++) {
        cout << "Term " << (i+1) << " - Coefficient: ";
        cin >> coeff;
        cout << "Term " << (i+1) << " - Power: ";
        cin >> power;
        p2.insertTerm(coeff, power);
    }

    cout << "\nInput:" << endl;
    cout << "list1: ";
    p1.displayAsArray();
    cout << "\nlist2: ";
    p2.displayAsArray();

    Polynomial result = Polynomial::addPolynomials(p1, p2);

    cout << "\n\nPolynomial 1: ";
    p1.display();
    cout << "\nPolynomial 2: ";
    p2.display();
    cout << "\nResult: ";
    result.display();
    cout << "\n\nOutput: ";
    result.displayAsArray();
    cout << endl;

    return 0;
}
