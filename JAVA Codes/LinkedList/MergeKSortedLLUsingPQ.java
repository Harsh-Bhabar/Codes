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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(ListNode list: lists){
            while(list != null){
                pq.offer(list.val);
                list = list.next;
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while(!pq.isEmpty()){
            ListNode newNode = new ListNode(pq.peek());
            pq.poll();
            curr.next = newNode;
            curr = newNode;
        }

        return dummy.next;

    }
}