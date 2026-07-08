// Balanced Binary Tree 
#include<iostream>
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
    cout<<"Enter the value of the node:";
    cin>>val;
    if(val==-1){
        return NULL;
    }
    Node* root=new Node(val);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

int getHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int left=getHeight(root->left)+1;
    int right=getHeight(root->right)+1;
    return max(left,right);
}



bool balancedBinaryTree(Node* root){
    if(root==NULL){
        return true;
    }
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    int absoluteHeight=abs(leftHeight-rightHeight);
    if(absoluteHeight>1){
        return false;
    }
    bool left=balancedBinaryTree(root->left);
    bool right=balancedBinaryTree(root->right);
    if(left && right){
        return true;
    }
    return false;
}

int main(){
    Node* root=buildTree();
    cout<<endl<<"Tree Build successfully"<<endl;
    
    if(balancedBinaryTree(root)){
        cout<<"The tree is balanced!"<<endl;
    }
    else{
        cout<<"The tree is not balanced"<<endl;
    }
    return 0;
}