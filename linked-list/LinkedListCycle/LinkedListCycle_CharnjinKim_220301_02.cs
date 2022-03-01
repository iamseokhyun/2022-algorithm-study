using System;
using System.Collections.Generic;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
    public bool HasCycle(ListNode head) {
        if (head ==null) {
            return false;
        }
        bool ans = false;
        ListNode tmp = null;
        while (head.next!=null) {
            Put(ref tmp, ref head, ref ans);
            head=tmp;
            if (ans) {
                return ans;
            }
        }
         return ans;
    }
    public void Put(ref ListNode tmp, ref ListNode head, ref bool ans) {
        if (head.next.val==int.MaxValue) {
            ans = true;
            return;
        }
        tmp= head.next;
        head.val=int.MaxValue;
        return;
    }
}