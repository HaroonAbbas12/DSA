#include <iostream>
using namespace std;
template <typename DataItem>
class Stack {
private:
DataItem* stackArray; // Pointer to stack elements
int capacity; // Current capacity of the stack
int top; // Index of the top element
// Function to resize the stack array
void resize(int newCapacity) {
DataItem* newArray = new DataItem[newCapacity];
for (int i = 0; i <= top; i++) {
newArray[i] = stackArray[i];
}
delete[] stackArray;
stackArray = newArray;
capacity = newCapacity;
}
public:
// Constructor: Creates an empty stack
Stack(int ignored = 0) : capacity(10), top(-1) {
stackArray = new DataItem[capacity];
}
// Destructor: Frees memory used by the stack
~Stack() {
delete[] stackArray;
}
// Push: Adds an element to the top of the stack
void push(const DataItem item) {
if (top == capacity - 1) {
resize(capacity * 2); // Double the capacity if full
}
stackArray[++top] = item;
}
// Pop: Removes the top element from the stack
void pop() {
if (isEmpty()) {
cout << "Stack is empty. Cannot pop." << endl;
return;
}
top--; // Decrement the top index
}
// Peek: Returns the top element without removing it
DataItem peek() const {
if (isEmpty()) {
throw runtime_error("Stack is empty. Cannot peek.");
}
return stackArray[top];
}
// Clear: Removes all elements from the stack
void clear() {
top = -1; // Reset the stack to an empty state
}
// isEmpty: Checks if the stack is empty
bool isEmpty() const {
return top == -1;
}
};
int main() {
// Demonstrating the custom stack
Stack<int> stack;
cout << "Pushing elements 10, 20, 30 onto the stack." << endl;
stack.push(10);
stack.push(20);
stack.push(30);
cout << "Element at top of stack: " << stack.peek() << endl;
cout << "Popping the top element." << endl;
stack.pop();
cout << "Element at top of stack after pop: " << stack.peek() << endl;
cout << "Clearing the stack." << endl;
stack.clear();
cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
return 0;
}