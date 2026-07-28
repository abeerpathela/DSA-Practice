// Convert Binary Tree To Doubly Linked List

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

void solve(Node* root, Node* &head, Node* &tail){
    if(root==NULL){
        return;
    }
    // LNR
    
    // L
    solve(root->left,head,tail);
    // N
    if(tail!=NULL){
        root->left=tail;
        tail->right=root;
        tail=root;
    }
    else{
        //left part of the ll is empty so this block executes 
        head=root;
        tail=root;
    }
    // R 
    solve(root->right,head,tail);
    
}
Node* BinaryTreeToDoublyLinkedList(Node* root){
    Node* head=NULL;
    Node* tail=NULL;
    solve(root,head,tail);
    return head;
}
int main()
{
    /*
              10
             /  \
            5    20
           / \   / \
          2   8 15 30
    */

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(2);
    root->left->right = new Node(8);

    root->right->left = new Node(15);
    root->right->right = new Node(30);


    Node* head = BinaryTreeToDoublyLinkedList(root);


    // Print DLL
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}