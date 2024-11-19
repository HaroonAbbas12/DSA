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
// Clear: Removes all elements from the queue
void clear() {
front = 0;
rear = -1;
size = 0;
cout << "Queue cleared!" << endl;
}
// isEmpty: Checks if the queue is empty
bool isEmpty() const {
return size == 0;
}
// Count: Returns the number of elements in the queue
int count() const {
return size;
}
private:
// Resize the queue array
void resize(int newCapacity) {
DataItem* newArray = new DataItem[newCapacity];
for (int i = 0; i < size; i++) {
newArray[i] = queueArray[(front + i) % capacity];
}
delete[] queueArray;
queueArray = newArray;
front = 0;
rear = size - 1;
capacity = newCapacity;
}
};
int main() {
// Demonstrating the queue
Queue<int> queue;
cout << "Enqueuing elements: 10, 20, 30" << endl;
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
cout << "Number of elements in the queue: " << queue.count() << endl;
cout << "Clearing the queue..." << endl;
queue.clear();
cout << "Number of elements in the queue after clearing: " << queue.count() << endl;
cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
return 0;
}