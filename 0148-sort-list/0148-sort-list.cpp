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
    ListNode* merge(ListNode* leftSort,ListNode* rightSort){
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;

        ListNode* temp1=leftSort;
        ListNode* temp2=rightSort;

        while(temp1!=NULL && temp2!=NULL){
           
            if(temp1->val<temp2->val){
                
                if(newHead==NULL && newTail==NULL){
                    newHead=temp1;
                    newTail=temp1;
                }
                else{
                    newTail->next=temp1;
                    newTail=temp1;
                }
                temp1=temp1->next;
            }
            else{
                
                if(newHead==NULL && newTail==NULL){
                    newHead=temp2;
                    newTail=temp2;
                }
                else{
                    newTail->next=temp2;
                    newTail=temp2;
                }
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL){
            newTail->next=temp1;
        }
        if(temp2!=NULL){
            newTail->next=temp2;
        }
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        ListNode* previous=NULL;
        while(fast!=NULL && fast->next!=NULL){
            previous=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        previous->next=NULL;

        ListNode* leftSort=sortList(head);
        ListNode* rightSort=sortList(slow);
        return merge(leftSort,rightSort);
    }
};