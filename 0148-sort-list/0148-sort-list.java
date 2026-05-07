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
    public ListNode merge(ListNode leftSort, ListNode rightSort){
        ListNode newHead=null;
        ListNode newTail=null;
        if(leftSort.val<rightSort.val){
            newHead=leftSort;
            newTail=leftSort;
            leftSort=leftSort.next;
        }
        else{
            newHead=rightSort;
            newTail=rightSort;
            rightSort=rightSort.next;
        }
        while(leftSort!=null && rightSort!=null){
            if(leftSort.val<rightSort.val){
                newTail.next=leftSort;
                newTail=leftSort;
                leftSort=leftSort.next;
            }
            else{
                newTail.next=rightSort;
                newTail=rightSort;
                rightSort=rightSort.next;
            }
        }
        if(leftSort!=null){
            newTail.next=leftSort;
        }
        if(rightSort!=null){
            newTail.next=rightSort;
        }

        return newHead;
    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null){
            return head;
        }

        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=null;
        while(fast!=null && fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode mid=slow;
        prev.next=null;
        ListNode leftSort=sortList(head);
        ListNode rightSort=sortList(mid);
        return merge(leftSort,rightSort);
    }
}