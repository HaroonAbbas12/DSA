#include <iostream>

using namespace std;

// Function to implement Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test 1: Completely unsorted array
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Test 1: Unsorted Array\n";
    insertionSort(arr1, size1);
    cout << "Sorted Array: ";
    printArray(arr1, size1);
    cout << endl;

    // Test 2: Nearly sorted array
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 20, 10, 12};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Test 2: Nearly Sorted Array\n";
    insertionSort(arr2, size2);
    cout << "Sorted Array: ";
    printArray(arr2, size2);
    cout << endl;

    // Test 3: Another completely unsorted array
    int arr3[] = {12, 11, 13, 5, 6};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Test 3: Another Unsorted Array\n";
    insertionSort(arr3, size3);
    cout << "Sorted Array: ";
    printArray(arr3, size3);
    cout << endl;

    return 0;
}
