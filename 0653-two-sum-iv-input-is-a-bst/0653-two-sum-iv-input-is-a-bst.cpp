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
    void storeInorder(TreeNode* root, vector<int>& arr){
        if(root==NULL){
            return;
        }
        // LNR
        storeInorder(root->left,arr);
        arr.push_back(root->val);
        storeInorder(root->right,arr);
    }
    bool checkTwoSum(vector<int>& arr,int k){
        int i=0;
        int j=arr.size()-1;

        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==k){
                return true;
            }

            if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        // Store In order traversal in an array 
        vector<int>arr;
        storeInorder(root,arr);

        // check for the two sum 
        bool ans=checkTwoSum(arr,k);

        // return answer
        return ans;
    }
};