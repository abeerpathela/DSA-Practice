/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {

        ListNode oddHead=null;
        ListNode oddTail=null;

        ListNode evenHead=null;
        ListNode evenTail=null;

        ListNode current=head;
        int size=1;
        while(current!=null){
            ListNode newNode = new ListNode(current.val);
            if(size%2!=0){
                if(oddHead==null){
                    oddHead=newNode;
                    oddTail=newNode;
                }
                else{
                    oddTail.next=newNode;
                    oddTail=newNode;
                }
            }
            else{
                if(evenHead==null){
                    evenHead=newNode;
                    evenTail=newNode;
                }
                else{
                    evenTail.next=newNode;
                    evenTail=newNode;
                }
            }
            current=current.next;
            size++;
        }
        ListNode newHead=new ListNode();
        if(oddHead!=null){
            newHead=oddHead;
            if(evenHead!=null){
                oddTail.next=evenHead;
            }
            else{
                oddTail.next=null;
            }
        }
        else{
            newHead=evenHead;
        }
        return newHead;
    }
}