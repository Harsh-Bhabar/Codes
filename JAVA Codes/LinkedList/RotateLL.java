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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return head;
        }

        int len = 1;
        ListNode curr = head;
        while(curr.next != null){
            curr = curr.next;
            len += 1;
        }

        if(k == len){
            return head;
        }

        k %= len;
        k = len - k;
        curr.next = head;

        while(k > 0){
            k -= 1;
            curr = curr.next;
        }

        head = curr.next;
        curr.next = null;

        return head;
    }
}