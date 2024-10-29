#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value < root->data)
    {

        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root ->right = insert(root->right, value);
    }
    return root;
}
void inOrderTraversal(Node* root){
    if(root == nullptr) return;
    inOrderTraversal(root->left);     //visit left subtree
    cout<< root->data<<" ";            //print the nodes value
    inOrderTraversal(root->right);    // visit right subtree
}

void preOrderTraversal(Node* root){
    if(root == nullptr) return;
    cout<< root->data<<" "; 
    preOrderTraversal(root->left);            //print the nodes value
    preOrderTraversal(root->right);    // visit right subtree
}

void postOrderTraversal(Node* root){
    if(root == nullptr) return;
    postOrderTraversal(root->left);            //print the nodes value
    postOrderTraversal(root->right); 
    cout<< root->data<<" ";                  // visit right subtree
}
// bool search(Node* root,int value){
//     if(root == nullptr) return false;
//     if(root->data == value) return true;

//     if(value<root->data){
//         return search(root->left,value);
//     }
//     else {
//         return search(root->right,value);
//     }
// }
int main(){
    Node* root = nullptr;   // start with an empty tree

    int value,n;
    cout<<"enter the value "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"enter the value :"<<i+1<<" : "<<"";
        cin>>value;
        root=insert(root,value);
    }
        
    // root = insert(root,50);
    // root = insert(root,30);
    // root = insert(root,20);
    // root = insert(root,40);
    // root = insert(root,70);
    // root = insert(root,60);
    // root = insert(root,80);
    
    cout<<"\n"<<"In-order traversal of th BST : ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"\n"<< "pre-order traversal of th BST : "; 
    preOrderTraversal(root);
    cout<<endl;
    cout<<"\n"<< "post-order traversal of th BST : "; 
    postOrderTraversal(root);
    cout<<endl;

    // int key=40;
    // if(search(root,key)){
    //     cout<<"\n"<<key<<" found in the bst \n";
    // }
    // else{
    //     cout<<"\n"<<key<<"not found in the bst \n ";
    // }
    
     return 0;
   
}
