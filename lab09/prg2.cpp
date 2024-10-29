#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input() {
        cout << "Enter ID: ";
        cin >> per_id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

class Node {
public:
    Person data;
    Node* next;

    Node(const Person& p) : data(p), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void addQueue(const Person& p) {
        Node* newNode = new Node(p);
        if (!rear) front = newNode;
        else rear->next = newNode;
        rear = newNode;
    }

    void removeQueue() {
        if (front) {
            Node* temp = front;
            front = front->next;
            temp->data.output();
            delete temp;
            if (!front) rear = nullptr;
        }
    }
};

int main() {
    Queue queue;
    int choice;

    do {
        cout << "\n1. Add Person\n2. Remove Person\n3. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Person p;
            p.input();
            queue.addQueue(p);
            break;
        }
        case 2: queue.removeQueue(); break;
        case 3: cout << "Exiting." << endl; break;
        default: cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
