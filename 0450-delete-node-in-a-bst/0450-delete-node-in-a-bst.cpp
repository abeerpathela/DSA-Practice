/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMax(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            // target / key ko match hogaya hai  
            
            // delete node with 0 child 
            if(root->left==NULL && root->right==NULL){
                TreeNode* temp=root;
                delete temp;
                return NULL;
            }
            // delete node with 1 child at left 
            if(root->left!=NULL && root->right==NULL){
               TreeNode* temp=root;
                TreeNode* child=root->left;
                temp->left=NULL;
                delete temp;
                return child;
            }
            // delete node with 1 child at right 
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root;
                TreeNode* child=root->right;
                temp->right=NULL;
                delete temp;
                return child;
            }
            // delete node with 2 children 
            if(root->left!=NULL && root->right!=NULL){
                int replaceValue=getMax(root->left);
                root->val=replaceValue;
                root->left=deleteNode(root->left,replaceValue);
                return root;
            }
        }
        else{
            // Agar value match nahi hui hai tabh is else mei woh aayega jisme us element ko hume find karna hoga 
            if(key>root->val){
                // deletion right side me hoga 
                root->right=deleteNode(root->right,key);
            }
            else{
                // deletion left side mei hoga 
                root->left=deleteNode(root->left,key);
            }
        }
        return root;
    }
};