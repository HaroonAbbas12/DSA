#include <iostream>

using namespace std;

// Bubble Sort to arrange SAP IDs in descending order
void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the element found is less than the next element
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Sort and display using Bubble Sort
    bubbleSortDescending(sapIDs, size);
    cout << "Sorted SAP IDs (Bubble Sort - Descending):\n";
    printSAPIDs(sapIDs, size);

    return 0;
}
