//Tree practice of implementation 
#include <iostream>
#include<queue>
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

Node* buildTree(){
    int val;
    cout<<"Enter the value for the node:";
    cin>>val;
    if(val==-1){
        return NULL;
    }
    Node* root = new Node(val);
    root->left= buildTree();
    root->right = buildTree();
    return root;
};

void preOrder(Node* root){ // NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" "; // N
    preOrder(root->left); // L
    preOrder(root->right); // R
}

void inOrder(Node* root){ // LNR
    if(root==NULL){
        return;
    }
    inOrder(root->left); // L
    cout<<root->data<<" "; // N
    inOrder(root->right); // R
}

void postOrder(Node* root){ // LRN
    if(root==NULL){
        return;
    }
    postOrder(root->left); // L
    postOrder(root->right); // R
    cout<<root->data<<" "; // N
}

// void levelOrderTraversal(Node* root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node* front=q.front();
//         q.pop();
//         if(front==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<front->data<<" ";
//             if(front->left!=NULL){
//                 q.push(front->left);
//             }
//             if(front->right!=NULL){
//                 q.push(front->right);
//             }
//         }
//     }
// }

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){ // To detect that the next level of the tree has started 
            cout<<endl;
            if(!q.empty()){ // if the tree has got to its end 
                q.push(NULL);
            }
        } 
        else{ // For the same level in the tree 
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}


int main()
{
    Node* root = buildTree();
    
    cout<<endl<<"preOrder Traversal :"<<endl;
    preOrder(root);
    cout<<endl<<"inOrder Traversal :"<<endl;
    inOrder(root);
    cout<<endl<<"postOrder Traversal :"<<endl;
    postOrder(root);
    cout<<endl<<"levelOrderTraversal :"<<endl;
    levelOrderTraversal(root);

    cout <<endl<< "Tree created successfully.";

    return 0;
}