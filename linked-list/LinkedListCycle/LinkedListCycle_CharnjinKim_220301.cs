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
using System;
using System.Collections.Generic;

public class Solution {
    public bool HasCycle(ListNode head) {
        if (head ==null) {
            return false;
        }
         List<ListNode> visited = new List<ListNode>();
        while(head.next!=null) {
            if (visited.Contains(head.next)) {
                return true;
            } else {
                visited.Add(head.next);
                head = head.next;
            }
        }
        return false;
    }
}