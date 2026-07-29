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
    int index=0;
    TreeNode* build(vector<int>& preorder,int minVal, int maxVal) {
        if(index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal){
            return NULL;
        }
        // N
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        // L R
        root->left=build(preorder,minVal,root->val);

        root->right=build(preorder,root->val,maxVal);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder){
        return build(preorder,INT_MIN,INT_MAX);
    }
};