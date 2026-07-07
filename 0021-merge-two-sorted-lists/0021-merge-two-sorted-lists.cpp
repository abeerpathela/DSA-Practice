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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2!=NULL){
            return list2;
        }
        if(list1!=NULL && list2==NULL){
            return list1;
        }
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;

        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=NULL && temp2!=NULL){
            ListNode* newNode=new ListNode();

            if(temp1->val<temp2->val){

                if(newHead==NULL && newTail==NULL){

                    newNode->val=temp1->val;
                    newHead=newNode;
                    newTail=newNode;

                }
                else{

                    newNode->val=temp1->val;
                    newTail->next=newNode;
                    newTail=newNode;

                }

                temp1=temp1->next;

            }
            else if(temp2->val<temp1->val){
                if(newHead==NULL && newTail==NULL){

                    newNode->val=temp2->val;
                    newHead=newNode;
                    newTail=newNode;

                }
                else{

                    newNode->val=temp2->val;
                    newTail->next=newNode;
                    newTail=newNode;

                }

                temp2=temp2->next;
            }
            else{
                if(newHead==NULL && newTail==NULL){

                    newNode->val=temp2->val;
                    newHead=newNode;
                    newTail=newNode;

                }
                else{

                    newNode->val=temp2->val;
                    newTail->next=newNode;
                    newTail=newNode;

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
};