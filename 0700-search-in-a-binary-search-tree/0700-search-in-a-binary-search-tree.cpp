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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        
        if(val < root->val){
            TreeNode* leftAns=searchBST(root->left,val);
            if(leftAns!=NULL){
                return leftAns;
            }
        }

        if(val > root->val){
            TreeNode* rightAns=searchBST(root->right,val);
            if(rightAns!=NULL){
                return rightAns;
            }
        }

        return NULL;
    }
};