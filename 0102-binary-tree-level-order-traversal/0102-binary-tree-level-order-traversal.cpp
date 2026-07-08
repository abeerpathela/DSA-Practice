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
    void helperFunction(TreeNode* root,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>oneLevel;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                ans.push_back(oneLevel);
                oneLevel.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                oneLevel.push_back(front->val);
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        helperFunction(root,ans);
        return ans;
    }
};