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
void reverse(Node *node)
{
    if (node == NULL)
    {
        cout << "list is empty";
        return;
    }
    while (node->next != NULL)
    {
        node = node->next;
    }

    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->prev;
    }
    cout << "null" << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printForward(head);
    reverse(head);
    

    return 0;
}
