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
    public int sizeOfLL(ListNode head){
        ListNode current=head;
        int size=0;
        while(current!=null){
            size++;
            current=current.next;
        }
        return size;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size=sizeOfLL(head);
        int target=size-n+1;

        if(target==1){
            return head.next;
        }
        int i=1;
        ListNode current=head;

        while(current!=null && i<target-1){
            current=current.next;
            i++;
        }
        current.next=current.next.next;
        return head;
    }
}