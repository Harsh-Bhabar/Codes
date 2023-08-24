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

    ListNode mergeTwoLL(ListNode l1, ListNode l2){
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                curr.next = l1;
                l1 = l1.next;
            }else{
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        if(l1 != null){
            curr.next = l1;
        }
        if(l2 != null){
            curr.next = l2;
        }
        return dummy.next;
    }

    ListNode breakAndJoin(ListNode[] lists, int l, int r){
        if(l > r){
            return null;
        }
        if(l == r){
            return lists[l];
        }
        int mid = l + (r-l)/2;
        ListNode l1 = breakAndJoin(lists, l, mid);
        ListNode l2 = breakAndJoin(lists, mid+1, r);
        return mergeTwoLL(l1, l2);
    }

    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        if( k == 0){
            return null;
        }
        return breakAndJoin(lists, 0, k-1);
    }
}