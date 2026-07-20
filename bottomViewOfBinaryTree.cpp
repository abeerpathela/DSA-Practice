// Bottom View of binary tree 

#include <iostream>
#include<vector>
#include<queue>
#include<map>
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



vector<int> bottomView(Node* root){
    vector<int>ans;
    
    if(root==NULL){
        return ans;
    }
    
    map<int,int>mp;
    
    queue<pair<Node*,int>>q;
    
    q.push({root,0});
    
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        
        Node* node=temp.first;
        int col=temp.second;
        
        mp[col]=node->data;
        
        if(node->left){
            q.push({node->left,col-1});
        }
        
        if(node->right){
            q.push({node->right,col+1});
        }
    
    }
    
    for(auto x:mp){
        ans.push_back(x.second);
    }
    
    return ans;
}


int main(){

    /*
             1
           /   \
          2     3
           \     \
            4     5
             \
              6
    */


    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->left->right->right = new Node(6);

    root->right->right = new Node(5);



    vector<int> ans = bottomView(root);


    cout<<"Bottom View: ";

    for(int x: ans){
        cout<<x<<" ";
    }


    return 0;
}