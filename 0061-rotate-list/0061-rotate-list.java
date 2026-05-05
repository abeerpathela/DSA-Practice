class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;

        // 1. Find length
        ListNode temp = head;
        int n = 1;

        while(temp.next != null){
            temp = temp.next;
            n++;
        }

        // 2. Make circular
        temp.next = head;

        // 3. Reduce k
        k = k % n;

        // 4. Find new tail
        int steps = n - k;
        ListNode newTail = head;

        for(int i = 1; i < steps; i++){
            newTail = newTail.next;
        }

        // 5. Break and return
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}