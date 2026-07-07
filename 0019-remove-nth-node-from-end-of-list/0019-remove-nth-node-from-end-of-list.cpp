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
    int sizeOfLL(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int position=sizeOfLL(head)-n+1;

        if(position==1){
            ListNode* toDelete=head;
            head=head->next;
            delete toDelete;
            return head;
        }

        // else 
        ListNode* previous=NULL;
        ListNode* current=head;
        int Cposition=1;
        while(Cposition<position){
            ListNode* forward=current->next;
            previous=current;
            current=forward;
            Cposition++;
        }
        previous->next=current->next;
        delete current;
        return head;
    }
};