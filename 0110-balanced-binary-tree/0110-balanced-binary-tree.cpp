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
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=getHeight(root->left)+1;
        int right=getHeight(root->right)+1;
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        int absoluteHeight=abs(leftHeight-rightHeight);

        if(absoluteHeight>1){
            return false;
        }
        // else 
        bool leftAnswer=isBalanced(root->left);
        bool rightAnswer=isBalanced(root->right);
        if(leftAnswer && rightAnswer){
            return true;
        }
        return false;

    }
};