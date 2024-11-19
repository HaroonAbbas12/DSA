#include <iostream>
using namespace std;
template <typename DataItem>
class Queue {
private:
DataItem* queueArray; // Pointer to queue elements
int capacity; // Current capacity of the queue
int front; // Index of the front element
int rear; // Index of the rear element
int size; // Current size of the queue
// Function to resize the queue when it overflows
void resize(int newCapacity) {
DataItem* newArray = new DataItem[newCapacity];
int index = 0;
// Copy elements to the new array in correct order
for (int i = 0; i < size; i++) {
newArray[i] = queueArray[(front + i) % capacity];
}
delete[] queueArray;
queueArray = newArray;
front = 0;
rear = size - 1;
capacity = newCapacity;
}
public:
// Constructor: Initializes an empty queue
Queue(int initialCapacity = 10)
: capacity(initialCapacity), front(0), rear(-1), size(0) {
queueArray = new DataItem[capacity];
}
// Destructor: Frees memory used by the queue
~Queue() {
delete[] queueArray;
}
// Enqueue: Adds an element to the rear of the queue
void enqueue(const DataItem item) {
if (size == capacity) {
resize(capacity * 2); // Double the capacity if the queue overflows
}
rear = (rear + 1) % capacity;
queueArray[rear] = item;
size++;
}
// Dequeue: Removes an element from the front of the queue
void dequeue() {
if (isEmpty()) {
cout << "Queue is empty. Cannot dequeue." << endl;
return;
}
front = (front + 1) % capacity;
size--;
}
// Peek: Returns the front element without removing it
DataItem peek() const {
if (isEmpty()) {
throw runtime_error("Queue is empty. Cannot peek.");
}
return queueArray[front];
}
// isEmpty: Checks if the queue is empty
bool isEmpty() const {
return size == 0;
}
// getSize: Returns the current size of the queue
int getSize() const {
return size;
}
};
int main() {
// Demonstrating the dynamic queue
Queue<int> queue;
cout << "Enqueuing elements: 10, 20, 30" << endl;
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
cout << "Front element: " << queue.peek() << endl;
cout << "Dequeuing an element." << endl;
queue.dequeue();
cout << "Front element after dequeue: " << queue.peek() << endl;
cout << "Enqueuing more elements to trigger resize." << endl;
for (int i = 1; i <= 10; i++) {
queue.enqueue(i * 10);
}
cout << "Queue size after resizing: " << queue.getSize() << endl;
cout << "Front element: " << queue.peek() << endl;
return 0;
}