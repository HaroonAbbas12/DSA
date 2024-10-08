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
void deleteNode(Node** head,int key){
    Node* temp =*head;
    Node* prev = NULL;

    if (temp !=NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    //search for the key to be deleted
    while (temp != NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }
    if (temp ==NULL){
        cout<<"value not found in the list."<<endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
   
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
   cout<<"How many values do ou want to insert in the list \n";
   cin>>num;
   for(int i=0;i<num;i++)
   {
    cout<<"Enter the value :"<< i+1 << " :";
    cin>>value;

    insertAtEnd(&head,value);
   }
 
    printList(head);

}