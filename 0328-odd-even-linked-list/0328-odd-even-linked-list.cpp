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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* oddHead=NULL;
        ListNode* oddTail=NULL;

        ListNode* evenHead=NULL;
        ListNode* evenTail=NULL;

        ListNode* temp=head;
        int position=1;
        while(temp!=NULL){
            ListNode* newNode=new ListNode(temp->val);
            if(position%2==0){
                if(evenHead==NULL && evenTail==NULL){
                    evenHead=newNode;
                    evenTail=newNode;
                }
                else{
                    evenTail->next=newNode;
                    evenTail=newNode;
                }
            }
            else{
                if(oddHead==NULL && oddTail==NULL){
                    oddHead=newNode;
                    oddTail=newNode;
                }
                else{
                    oddTail->next=newNode;
                    oddTail=newNode;
                }
            }
            temp=temp->next;
            position++;
        }

        oddTail->next=evenHead;

        return oddHead;


    }
};