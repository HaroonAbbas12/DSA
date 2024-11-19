#include <iostream>

using namespace std;

// Insertion Sort to arrange SAP IDs in descending order
void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are less than key, to one position ahead
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the list of SAP IDs
void printSAPIDs(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main() {
    // Array of SAP IDs
    int sapIDs[] = {24904, 27773, 35622, 37532, 44172, 45804, 
                    45923, 46202, 46292, 46334, 46411, 46451, 
                    46465, 46488, 46980, 47231, 47419, 47527, 
                    47729};
    int size = sizeof(sapIDs) / sizeof(sapIDs[0]);

    cout << "Original SAP IDs:\n";
    printSAPIDs(sapIDs, size);

    // Sort and display using Insertion Sort
    insertionSortDescending(sapIDs, size);
    cout << "Sorted SAP IDs (Insertion Sort - Descending):\n";
    printSAPIDs(sapIDs, size);

    return 0;
}
