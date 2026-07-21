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
        // Base Cases
        if(root==NULL){
            return NULL;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        // CASE-1: p and q are on the same side 
        if( (p->val < root->val) && (q->val < root->val) ){
            TreeNode* leftAnswer=lowestCommonAncestor(root->left,p,q);
            if(leftAnswer!=NULL){
                return leftAnswer;
            }
        }
        // CASE-2: p and q are on the right side 
        if( (p->val > root->val) && (q->val > root->val) ){
            TreeNode* rightAnswer=lowestCommonAncestor(root->right,p,q);
            if(rightAnswer!=NULL){
                return rightAnswer;
            }
        }
        // CASE-3: p on the left side and q on the right side
        // return root 

        // CASE-4: p on the right side and q on the left side 
        // return root

        return root;
    }
};