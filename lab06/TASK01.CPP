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
void insertAtAnypoint(Node **head, int position, int newData)
{
    if (position <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, newData);
        return;
    }

    Node *temp = *head;
    int count = 1;

    while (temp && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFromPosition(Node **head, int position)
{
    if (*head == NULL || position <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        delete temp;
        return;
    }

    int count = 1;
    while (temp && count < position)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}

void deleteFromEnd(Node **head)
{
    // If the list is empty, return
    if (*head == NULL)
        return;

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
    insertAtAnypoint(&head,2,30);
    printForward(head);
    deleteFromPosition(&head,2);
    printForward(head);
  

    return 0;
}
