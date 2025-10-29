#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // Increase frequency
        freq[ch]++;

        // Add to queue if first occurrence
        if (freq[ch] == 1) {
            q.push(ch);
        }

        // Remove characters from front that have frequency > 1
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Print first non-repeating character or -1
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string (without spaces): ";
    cin >> str;

    cout << "Input: ";
    for (char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    firstNonRepeating(str);

    return 0;
}
