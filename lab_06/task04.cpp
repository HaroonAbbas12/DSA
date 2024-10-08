#include <iostream>
using namespace std;

// Node definition for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to get the middle element of a doubly linked list
Node* getMiddle(Node* head) {
    if (!head) return nullptr;  // List is empty

    Node* slow = head;
    Node* fast = head;

    // Move fast by two steps and slow by one step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // Slow pointer will be at the middle
}

// Helper function to insert a new node at the end
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    // Example: Add elements to the doubly linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    
    cout << "Doubly linked list: ";
    printList(head);

    // Find and print the middle element
    Node* middle = getMiddle(head);
    if (middle) {
        cout << "Middle element is: " << middle->data << endl;
    } else {
        cout << "List is empty" << endl;
    }

    return 0;
}
