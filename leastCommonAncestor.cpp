// Least Common Ancestor 

#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int value){
      this->data=value;
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
};

Node* leastCommonAncestor(Node* root,Node* p, Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root==p){
        return p;
    }
    if(root==q){
        return q;
    }
    Node* leftAnswer=leastCommonAncestor(root->left,p,q);
    Node* rightAnswer=leastCommonAncestor(root->right,p,q);
    if(leftAnswer==NULL && rightAnswer==NULL){
        return NULL;
    }
    if(leftAnswer!=NULL && rightAnswer==NULL){
        return leftAnswer;
    }
    if(leftAnswer==NULL && rightAnswer!=NULL){
        return rightAnswer;
    }
    return root;
}

Node* findNode(Node* root, int value){
    if(root == NULL){
        return NULL;
    }

    if(root->data == value){
        return root;
    }

    Node* left = findNode(root->left, value);
    if(left != NULL){
        return left;
    }

    return findNode(root->right, value);
}


int main(){

    Node* root = buildTree();

    cout << "\nTree built successfully.\n";

    int x, y;
    cout << "Enter first node: ";
    cin >> x;

    cout << "Enter second node: ";
    cin >> y;

    Node* p = findNode(root, x);
    Node* q = findNode(root, y);

    if(p == NULL || q == NULL){
        cout << "One or both nodes are not present in the tree.";
        return 0;
    }

    Node* ans = leastCommonAncestor(root, p, q);

    cout << "Least Common Ancestor: " << ans->data << endl;

    return 0;
}