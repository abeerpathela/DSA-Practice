/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    TreeNode* solve(ListNode* &head,int length){
        if(head==NULL){
            return NULL;
        }
        if(length<=0){
            return NULL;
        }
        // L
        TreeNode* leftSubtree=solve(head,length/2);
        // N
        int element=head->val;
        TreeNode* root=new TreeNode(element);
        root->left=leftSubtree;

        head=head->next;
        // R
        TreeNode* rightSubtree=solve(head,length-length/2-1);
        root->right=rightSubtree;
        // return answer
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int lengthOfLL=getLen(head);
        TreeNode* root=solve(head,lengthOfLL);
        return root;
    }
};