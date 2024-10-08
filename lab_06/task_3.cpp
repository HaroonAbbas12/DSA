#include <iostream>
using namespace std;

// Node structure
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

// Class for the doubly linked list
class LinkedList {
    Node* head;  // first element
    Node* tail;  // last element

public:
    LinkedList() {  // constructor
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end
    void addAtEnd(int val) {
        Node* newNode = new Node(val);  // allocate new node
        if (head == nullptr) {  // if list is empty
            head = newNode;  // first node becomes head and tail
            tail = newNode;
        } else {
            tail->next = newNode;  // add new node to the end
            newNode->prev = tail;  // link backwards
            tail = newNode;  // update tail
        }
    }

    // Forward traversal
    void printForward() {
        if (head == nullptr) {  // if list is empty
            cout << "The list is empty!" << endl;
            return;
        }

        Node* temp = head;  // start from head
        cout << "Forward: ";
        while (temp != nullptr) {  // traverse till the end
            cout << temp->data << " ";  // print each node's data
            temp = temp->next;  // move to next node
        }
        cout << endl;
    }

    // Backward traversal
    void printBackward() {
        if (tail == nullptr) {  // if list is empty
            cout << "The list is empty!" << endl;
            return;
        }

        Node* temp = tail;  // start from tail
        cout << "Backward: ";
        while (temp != nullptr) {  // traverse backwards
            cout << temp->data << " ";  // print each node's data
            temp = temp->prev;  // move to previous node
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;  // create linked list

    // Add some nodes to the list
    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);
    list.addAtEnd(40);
    list.addAtEnd(50);

    // Try traversing the list in both directions
    list.printForward();  // forward direction
    list.printBackward();  // backward direction

    return 0;
}
