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
    // reverse in order traversal  LNR TO RNL
    int sum=0;
    void reverseInOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        //R
        reverseInOrder(root->right);
        // N
        sum=sum+root->val;
        root->val=sum;
        // L
        reverseInOrder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        reverseInOrder(root);
        return root;
    }
};