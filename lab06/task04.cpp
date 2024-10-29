#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertAtBeginning(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

Node *findMiddle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    // Move fast by two nodes and slow by one node until fast reaches the end
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // slow is now pointing to the middle node
}

void printForward(Node *node)
{
    cout << "Forward traversal: ";
    while (node != NULL)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print list in forward order
    printForward(head);
    
    // Find and print the middle node
    Node *middle = findMiddle(head);
    if (middle != NULL)
    {
        cout << "Middle node: " << middle->data << endl;
    }
    else
    {
        cout << "List is empty" << endl;
    }

    return 0;
}
