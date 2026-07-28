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
class Info{
    public:
    long long minVal;
    long long maxVal;
    bool isBST;
};
class Solution {
public:
    Info solve(TreeNode* root){
        if(root==NULL){
            Info temp;
            temp.minVal=LLONG_MAX;
            temp.maxVal=LLONG_MIN;
            temp.isBST=true;
            return temp;
        }
        Info leftAns=solve(root->left);
        Info rightAns=solve(root->right);

        Info currentAns;
        currentAns.minVal=min((long long)root->val,min(leftAns.minVal,rightAns.minVal));
        currentAns.maxVal=max((long long)root->val,max(leftAns.maxVal,rightAns.maxVal));
        currentAns.isBST=false;
        if(((root->val > leftAns.maxVal) && (leftAns.isBST))&&((root->val < rightAns.minVal) && (rightAns.isBST))){
            currentAns.isBST=true;
        }
        return currentAns;
    }
    bool isValidBST(TreeNode* root) {
        Info ans=solve(root);
        return ans.isBST;
    }
};