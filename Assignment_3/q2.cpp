#include <iostream>
using namespace std;

#define MAX 100   

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';   
        } else {
            return arr[top--];
        }
    }
};

int main() {
    Stack s;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    for (char ch : str) {
        s.push(ch);
    }

    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}
