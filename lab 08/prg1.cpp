#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}
    void input() {
        cout << "Enter registration number: ";
        cin >> reg_no;
        cin.ignore(); // Ignore newline character
        cout << "Enter student name: ";
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void output() const {
        cout << "Reg No: " << reg_no << ", Name: " << st_name << ", CGPA: " << cgpa << endl;
    }
};

class Stack {
private:
    Student* arr;
    int top;
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new Student[size];
    }

    ~Stack() { delete[] arr; }

    void push(const Student& s) {
        if (top < capacity - 1) arr[++top] = s;
        else cout << "Stack overflow." << endl;
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped: ";
            arr[top--].output();
        } else cout << "Stack underflow." << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack stack(size);

    int choice;
    do {
        cout << "\n1. Push Student\n2. Pop Student\n3. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Student s;
            s.input();
            stack.push(s);
            break;
        }
        case 2: stack.pop(); break;
        case 3: cout << "Exiting." << endl; break;
        default: cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
