#include <algorithm>

static bool sort_cmp(ListNode* list1, ListNode* list2){
    if(list1 == nullptr) return false;
    if(list2 == nullptr) return true;
    return list1->val < list2->val;
}
static bool heap_cmp(ListNode* list1, ListNode* list2){
    return list1->val > list2->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;

    // sort_cmp를 통해 lists의 empty list를 모두 제거
    sort(lists.begin(), lists.end(), sort_cmp);
    for(int i=0;i<lists.size();i++)
        if(lists[i] == nullptr){
            lists.erase(lists.begin()+i, lists.end());
            break;
        } 
    if(lists.size() == 0) return nullptr;
        
    // head와 tail 초기화 및 heapify
    pop_heap(lists.begin(), lists.end(), heap_cmp);
    ListNode *head = lists.back(), *tail = lists.back();
    
    lists.back() = lists.back()->next;
    if(lists.back() == nullptr) lists.pop_back();
    make_heap(lists.begin(), lists.end(), heap_cmp);
     
    while(lists.size() > 1){
        pop_heap(lists.begin(), lists.end(), heap_cmp);
        tail->next = lists.back();
        tail = tail->next;
            
        lists.back() = lists.back()->next;
        if(lists.back() == nullptr) lists.pop_back();
        else push_heap(lists.begin(), lists.end(), heap_cmp);
    }
    tail->next = lists[0];
        
    return head;
} // runtime : 24 ms (faster than 84.15 %), memory usage : 13.1 MB (less than 84.88 %)?

/*
Time Complexity Analysis : k == lists.length, n = sum(lists[i].length)라 하면

[ sorting- O(k log k) ] + [ make heap - O(k) ] + [while loop - O(n) * push heap - O(log k)]

= O(n log k) ≤ O(n log n)

Space Complexity Analysis: O(1) (head, tail, for loop variable)

*/
