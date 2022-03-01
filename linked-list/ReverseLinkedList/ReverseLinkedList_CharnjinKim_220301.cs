using System;
using System.Collections.Generic;

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