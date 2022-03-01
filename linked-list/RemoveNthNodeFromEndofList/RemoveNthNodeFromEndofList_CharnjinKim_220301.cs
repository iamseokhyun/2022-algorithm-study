using System;
using System.Collections.Generic;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        if (head.next==null) {
            return null;
        }
        int i=0;
        List<ListNode> res = new List<ListNode>();
        for (;head!=null;i++) {
            res.Add(head);
            head = head.next;
        }
        if (n==res.Count) {
            return res[1];
        } else if (n==1) {
            res[i-2].next=null;
        } else {
            res[res.Count-n-1].next=res[res.Count-n+1];
        }
        return res[0];
    }
}   