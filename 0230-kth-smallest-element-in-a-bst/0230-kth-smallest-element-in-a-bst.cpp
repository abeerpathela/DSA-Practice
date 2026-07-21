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
    void storeInOrder(TreeNode* root,vector<int>& ans){ //LNR
        if(root==NULL){
            return;
        }
        storeInOrder(root->left,ans);
        ans.push_back(root->val);
        storeInOrder(root->right,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal store in the array
        vector<int>ans;
        storeInOrder(root,ans); 
        return ans[k-1];
    }
};