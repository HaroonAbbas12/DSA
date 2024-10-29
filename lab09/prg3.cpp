#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    Queue(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue overflow." << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (!rear) front = newNode;
        else rear->next = newNode;
        rear = newNode;
        size++;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue underflow." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Removed: " << temp->data << endl;
        delete temp;
        size--;
        if (!front) rear = nullptr;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    Queue queue1(5), queue2(5);
    int choice, value;

    do {
        cout << "\n1. Add to Queue 1\n2. Remove from Queue 1\n3. Remove from Queue 2\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            queue1.enqueue(value);
            break;
        case 2:
            if (!queue1.isEmpty()) {
                queue1.dequeue();
                queue2.enqueue(value);
            } else {
                queue1.dequeue();
            }
            break;
        case 3:
            queue2.dequeue();
            break;
        case 4:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
