#include <iostream>
using namespace std;
struct Node
{
    int data; // insert anywhere//indert at end ,delete at the end //delete at the end
    Node *prev;
    Node *next; // pointer to next node
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
void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    Node *last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}
void deleteFromEnd(Node **head)
{
    // If the list is empty, return
    if (*head == NULL)
    {
        cout<<"list is empty"<<endl;
        return;

    }

    // Start from the head node
    Node *temp = *head;

    // Traverse to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // If there's only one node in the list
    if (temp->prev == NULL)
    {
        *head = NULL; // The list will be empty after deletion
    }
    else
    {
        // Update the second-last node's next to NULL
        temp->prev->next = NULL;
    }

    // Free the memory of the last node
    delete temp;
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
    Node *tail = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printForward(head);
    cout << endl;
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    insertAtEnd(&head, 80);
    cout << endl;
    printForward(head);
    deleteFromEnd(&head);
    printForward(head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    printForward(head);

    return 0;
}
