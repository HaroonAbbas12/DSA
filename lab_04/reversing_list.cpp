#include <iostream>
using namespace std;

// Node structure to represent a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move 'prev' and 'current' one step forward
        current = next;
    }
    head = prev;  // Update the head to the new first node
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;  // Start with an empty list
    int n, value;

    // Creating the linked list with user input
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to create the linked list:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertNode(head, value);
    }

    // Display the original list
    cout << "Original ";
    displayList(head);

    // Reverse the linked list
    reverseList(head);

    // Display the reversed list
    cout << "Reversed ";
    displayList(head);

    return 0;
}
