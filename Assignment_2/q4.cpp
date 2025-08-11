#include <iostream>
using namespace std;

void concatenate(char s1[], char s2[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') i++; 
    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';
}

void reverseString(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;   
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void deleteVowels(char s[]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char ch = s[i];
        if (!(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||
              ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

void bubbleSort(char str[]) {
    int n = 0;
    while (str[n] != '\0') n++; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void toLowercase(char &ch) {
    if (ch >= 'A' && ch <= 'Z') ch = ch + 32;
}

int main() {
    int choice;
    do {
        cout << "\n---- String Operations Menu ----\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort characters in a string\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            char s1[100], s2[50];
            cout << "Enter first string: ";
            cin.getline(s1, 100);
            cout << "Enter second string: ";
            cin.getline(s2, 50);
            concatenate(s1, s2);
            cout << "Concatenated string: " << s1 << "\n";
        }
        else if (choice == 2) {
            char s[100];
            cout << "Enter string to reverse: ";
            cin.getline(s, 100);
            reverseString(s);
            cout << "Reversed string: " << s << "\n";
        }
        else if (choice == 3) {
            char s[100];
            cout << "Enter string: ";
            cin.getline(s, 100);
            deleteVowels(s);
            cout << "String without vowels: " << s << "\n";
        }
        else if (choice == 4) {
            char s[100];
            cout << "Enter string: ";
            cin.getline(s, 100);
            bubbleSort(s);
            cout << "Sorted string: " << s << "\n";
        }
        else if (choice == 5) {
            char ch;
            cout << "Enter uppercase character: ";
            cin >> ch;
            toLowercase(ch);
            cout << "Lowercase: " << ch << "\n";
            cin.ignore(); 
        }
        else if (choice == 6) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
