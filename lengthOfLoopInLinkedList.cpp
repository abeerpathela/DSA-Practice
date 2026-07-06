#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    
    Node(int data){
        val=data;
        next=NULL;
    }
};

int lengthOfLL(Node* &head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            slow=head;
            int count=1;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
                count++;
            }
            return count;
        }
    }
    
    return -1;
}

int main(){
    Node* head=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    Node* c=new Node(40);
    Node* d=new Node(50);
    
    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    
    cout<<lengthOfLL(head);
    
    
}