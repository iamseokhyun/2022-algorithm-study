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
    public ListNode MergeKLists(ListNode[] lists) {
        List<int> valList = new List<int> () ;
        foreach (ListNode item in lists) {
            valList.AddRange(rtnVal(item));
        }
        valList = valList.OrderBy(x=>x).ToList();
        List<ListNode> res = new List<ListNode>();
        for(int i =0;i<valList.Count;i++) {
            res.Add(new ListNode(valList[i], null));
        }
        for (int i =0;i<valList.Count-1;i++) {
            res[i].next = res[i+1];
        }
        try {
            return res[0];
        } catch (Exception e) {
            return null;
        }
    }
    public List<int> rtnVal(ListNode li) {
        List<int> res = new List<int>();
        while (li!=null) {
            res.Add(li.val);
            li = li.next;
        }
        return res;
    }
}