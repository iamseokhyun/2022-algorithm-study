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
    public void ReorderList(ListNode head) {
        if (head==null) {
            return;
        }
        List<ListNode> mem = new List<ListNode>();
        while (head!=null) {
            mem.Add(head);
            head = head.next;
        }
        ListNode[] res = new ListNode[mem.Count];
        bool last = true;
        int i = 0;
        while (mem.Count>0) {
            if (last) {
                res[i]=(mem[0]);
                mem.RemoveAt(0);
                last = false;
                i++;
            }
            else {
                res[i]=(mem[mem.Count-1]);
                mem.RemoveAt(mem.Count-1);
                last=true;
                i++;
            }
        }
        for (int p =res.Length-1;p>0;p--) {
            res[p-1].next = res[p];
        }
        res[res.Length-1].next = null;
    }
}