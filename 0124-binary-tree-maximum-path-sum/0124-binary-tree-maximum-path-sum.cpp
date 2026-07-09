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
    int maxSum=INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=max(0,dfs(root->left));
        int right=max(0,dfs(root->right));

        maxSum=max(maxSum,left+right+root->val); // ye calculate karega ki present node ka distance max hai ya fer koi aur jo value hum end mei store karenge 

        return root->val+max(left,right); // ye return karega jo distance that us root se leke ya toh left node tak ya right node tak 
    }
    int maxPathSum(TreeNode* root) {
        int go=dfs(root);
        return maxSum;
    }
};