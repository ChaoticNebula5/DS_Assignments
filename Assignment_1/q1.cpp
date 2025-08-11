#include <bits/stdc++.h>

#define MAX_SIZE 100

using namespace std;



void createArray(int arr[], int &n) {
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void displayArray(int arr[], int n) {
	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insertElement(int arr[], int &n) {
	if (n >= MAX_SIZE) {
		cout << "Array is full!\n";
		return;
	}
	int pos, val;
	cout << "Enter position to insert: ";
	cin >> pos;
	cout << "Enter value: ";
	cin >> val;
	if (pos < 0 || pos > n) {
		cout << "Invalid position!\n";
		return;
	}
	for (int i = n; i > pos; i--)
		arr[i] = arr[i-1];
	arr[pos] = val;
	n++;
}

void deleteElement(int arr[], int &n) {
	int pos;
	cout << "Enter position to delete: ";
	cin >> pos;
	if (pos < 0 || pos >= n) {
		cout << "Invalid position!\n";
		return;
	}
	for (int i = pos; i < n-1; i++)
		arr[i] = arr[i+1];
	n--;
}

void linearSearch(int arr[], int n) {
	int val, found = 0;
	cout << "Enter value to search: ";
	cin >> val;
	for (int i = 0; i < n; i++) {
		if (arr[i] == val) {
			cout << "Found at position: " << i << endl;
			found = 1;
		}
	}
	if (!found)
		cout << "Not found!\n";
}

int main() {
	int arr[MAX_SIZE], n = 0, choice;
	while (true) {
		cout << "\nMENU\n";
		cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) createArray(arr, n);
		else if (choice == 2) displayArray(arr, n);
		else if (choice == 3) insertElement(arr, n);
		else if (choice == 4) deleteElement(arr, n);
		else if (choice == 5) linearSearch(arr, n);
		else if (choice == 6) {
			cout << "Exiting\n";
			break;
		} else {
			cout << "Invalid choice!\n";
		}
	}
	return 0;
}