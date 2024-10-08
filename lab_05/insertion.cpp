#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtBeginning(Node** head,int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}
void printList(Node* node)
{
    while (node != nullptr){
        cout<< node->data << " -> ";
        node = node ->next;
    }
    cout<<"NULL"<< endl;
}
int main()
{
    cout<<" \n\n*****************lab 05 linked list ********************\n\n"<<endl;
    Node* head = nullptr; 

    int num,value;
   cout<<"How manay values do ou want to insert at the beginning of the list ?";
   cin>>num;
   for(int i=0;i<num;i++)
   {
    cout<<"Enter the value :"<<i+1<<endl;
    cin>>value;

    insertAtBeginning(&head,value);
   }

    
    printList(head);

}