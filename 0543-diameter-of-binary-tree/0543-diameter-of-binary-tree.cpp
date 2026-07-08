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
    int maxHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=maxHeight(root->left)+1;
        int right=maxHeight(root->right)+1;
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int possibility1=maxHeight(root->left)+maxHeight(root->right);
        int possibility2=diameterOfBinaryTree(root->left);
        int possibility3=diameterOfBinaryTree(root->right);
        return max(possibility1,max(possibility2,possibility3));
    }
};