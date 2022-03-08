using System;
using System.Collections.Generic;
public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
        this.val = val;
        this.next = next;
    }
}
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if (head==null) {
            return head;
        }
        List<ListNode> res = new List<ListNode>();
        ListNode prevNext = null;
        while (head.next!=null) {
            res.Add(new ListNode(head.val, prevNext));
            prevNext = res[res.Count-1];
            head = head.next;
        }
        res.Add(new ListNode(head.val, prevNext));
        return res[res.Count-1];
    }
}