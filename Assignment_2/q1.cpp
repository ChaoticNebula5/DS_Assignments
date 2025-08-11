#include <iostream>
using namespace std;

int main() {
    int n, ele;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> ele;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == ele) {
            cout << "Element found at position " << mid + 1 << "\n";
            found = true;
            break;
        }
        else if (arr[mid] < ele) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }

    if (!found) {
        cout << "Element not found.\n";
    }

    return 0;
}
