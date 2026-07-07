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
class Solution {
public:
    ListNode* reverseTheList(ListNode* head){
       ListNode* current=head;
       ListNode* previous=NULL;

       while(current!=NULL){
            ListNode* forward=current->next;
            current->next=previous;
            previous=current;
            current=forward;
       } 

       return previous;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middleNode=findMid(head);
        ListNode* temp1=head;
        ListNode* temp2=reverseTheList(middleNode);

        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};