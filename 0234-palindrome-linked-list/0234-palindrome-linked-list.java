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
    public ListNode findMid(ListNode head){
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public ListNode reverseFromMid(ListNode head){
        ListNode previous=null;
        ListNode current=head;
        while(current!=null){
            ListNode forward=current.next;
            current.next=previous;
            previous=current;
            current=forward;
        }
        return previous;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        ListNode temp2=reverseFromMid(findMid(head));
        while( temp2!=null){
            if(temp.val!=temp2.val){
                return false;
            }
            temp=temp.next;
            temp2=temp2.next;
        }
        return true;
    }

}