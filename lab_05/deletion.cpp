#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;              //pointer to next node
};
void insertAtEnd(Node** head,int newData)
{
    //alocate memory for new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    // if the list is empty ,the new node becoes the head
    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next !=NULL){
        last = last->next;
    }
    last ->next = newNode;
}

void  deleteNode(Node** head,int key){
    if (head = NULL){
        cout<<"list is already empty";

    }
    
}
//function to print the linked list 
void printList(Node* node)
{
    while (node != NULL){
        cout<< node->data << " -> ";
        node = node ->next;
    }
    cout<<"NULL"<< endl;
}
int main()
{
    
    Node* head = NULL; 

    int num,value,deletevalue;
   cout<<"How many values do ou want to insert at the end of the list ?";
   cin>>num;
   for(int i=0;i<num;i++)
   {
    cout<<"Enter the value :"<<i+1<<endl;
    cin>>value;

    insertAtEnd(&head,value);
   }
 cout<<"the linked list is:";
    printList(head);
    cout<<"enter the value of the node to be deleted";
    cin>>deletevalue;
    delteNode(&head, deletevalue);
    cout<<"the linked list after deletion is :";
    printList(head);
    return 0;

    
   


}