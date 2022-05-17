#include <algorithm>

static bool cmp(ListNode*& node1, ListNode*& node2){    
    return node1->val > node2->val;    
}    
ListNode* mergeKLists(vector<ListNode*>& lists) {    
    if(lists.empty()) return nullptr;    
    
    // 1. remove empty linked list from vector lists
    int null_cnt = 0, size = lists.size();    
    for(int i=0;i<size-null_cnt;){    
        if(lists[i] == nullptr)    
            swap(lists[i], lists[size-++null_cnt]);    
        else i++;    
    }    
    lists.erase(lists.end()-null_cnt, lists.end());    
    if(lists.empty()) return nullptr;    
    
    // 2. merge k sorted lists using heap
    ListNode* head = new struct ListNode;    
    ListNode* pointNow = head;    
    make_heap(lists.begin(), lists.end(), cmp);    
    while(!lists.empty()){    
        pop_heap(lists.begin(), lists.end(), cmp);    
        pointNow->next = lists.back();    
    
        if(lists.back()->next != nullptr){      
            lists.back() = lists.back()->next;    
            push_heap(lists.begin(), lists.end(), cmp);    
        }   
        else lists.pop_back();          
    
        pointNow = pointNow->next;    
    }    
    return head->next;    
} // runtime : 24 ms (faster than 84.39 %), memory usage : 13 MB (less than 95.17 %)

/*
- If lists vector is empty or consists of only nullptrs, return empty linked list(nullptr).
- At procedure 1, we remove all empty linked list(or nullptr) from vector lists.
- At procedure 2, we build heap structure(ascending order) and connect 
  top node(node with lowest value) to the pointNow(will be merged list). 
  After connecting, push the connected node’s next node to the heap structure. 
  If it reaches the end of the list, remove the list. Repeat this procedure until lists is empty.
- Time complexity :
    O(k)(procedure 1) + O(k)(make heap) + O(n)(# repeat while loop)*O(log k)(push heap operation) ≤ O(n log n)
    (n: sum of lists[i].length)   
- Space complexity :
    O(1)(null_cnt, size(type int) / head, pointNow(type ListNode*))
*/
