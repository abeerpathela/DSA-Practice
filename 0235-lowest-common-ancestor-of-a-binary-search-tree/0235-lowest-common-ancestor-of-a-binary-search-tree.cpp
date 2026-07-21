/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* leftAnswer=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAnswer=lowestCommonAncestor(root->right,p,q);
        if(leftAnswer==NULL && rightAnswer==NULL){
            return NULL;
        }
        else if(leftAnswer!=NULL && rightAnswer==NULL){
            return leftAnswer;
        }
        else if(leftAnswer==NULL && rightAnswer!=NULL){
            return rightAnswer;
        }
        else{
            return root;
        }
    }
};