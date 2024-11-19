#include <iostream>

using namespace std;

// Function to implement Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    // Test 1: Already sorted array
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Test 1: Already Sorted Array\n";
    bubbleSort(arr1, size1);
    cout << "Sorted Array: ";
    printArray(arr1, size1);
    cout << endl;

    // Test 2: Reverse sorted array
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Test 2: Reverse Sorted Array\n";
    bubbleSort(arr2, size2);
    cout << "Sorted Array: ";
    printArray(arr2, size2);
    cout << endl;

    // Test 3: Random unsorted array
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Test 3: Random Unsorted Array\n";
    bubbleSort(arr3, size3);
    cout << "Sorted Array: ";
    printArray(arr3, size3);
    cout << endl;

    return 0;
}
