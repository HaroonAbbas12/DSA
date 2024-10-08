#include <iostream>        //updating an array
using namespace std;

int main() {
	int n = 5;
	int arr[5] = { 1, 2, 3, 4, 5 };
	int index;
	cout << "Original array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Enter the index of the element you want to delete (0 to " << n - 1 << "): ";
	cin >> index;
	if (index < 0 || index >= n) {
		cout << "Invalid index!" << endl;
		exit(0);
	}

	else
	{
		for (int i = index; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		cout << "Updated array: ";
		for (int i = 0; i < n - 1; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}