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
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if (list1==null && list2==null) {
            return list1;
        }
        List<ListNode> res = new List<ListNode>();
        while (list1!=null || list2!=null) {
            if (list1==null) {
                res.Add(list2);
                list2 = list2.next;
            } else if (list2==null) {
                res.Add(list1);
                list1 = list1.next;
            } else if (list2.val<=list1.val) {
                res.Add(list2);
                list2 = list2.next;
            } else {
                res.Add(list1);
                list1 = list1.next;
            }
        }
        for (int i =0;i<res.Count-1;i++) {
            res[i].next = res[i+1];
        }
        return res[0];
    }
}