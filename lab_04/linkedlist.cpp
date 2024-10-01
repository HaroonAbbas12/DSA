#include <iostream>
using namespace std;

// Node structure
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

// Function to insert a new node at the end of the list
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
    cout << "Node with value " << value << " inserted.\n";
}

// Function to delete a node by value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    if (head->data == value) {
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted.\n";
        return;
    }

    Node* prev = nullptr;
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node with value " << value << " deleted.\n";
}

// Function to search for a node by value
void searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node with value " << value << " found.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node with value " << value << " not found.\n";
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
    Node* head = nullptr;
    int value;

    // Creating the linked list with 5 nodes from user input
    cout << "Enter 5 values to create the linked list:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> value;
        insertNode(head, value);
    }

    displayList(head);

    // Performing insertion
    cout << "Enter a value to insert at the end of the list: ";
    cin >> value;
    insertNode(head, value);
    displayList(head);

    // Performing deletion
    cout << "Enter a value to delete from the list: ";
    cin >> value;
    deleteNode(head, value);
    displayList(head);

    // Performing search
    cout << "Enter a value to search in the list: ";
    cin >> value;
    searchNode(head, value);

    return 0;
}
