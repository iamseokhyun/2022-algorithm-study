#include <algorithm>

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return head;
    if(head->next == nullptr) return head;
        
    ListNode *pointNow = head->next, *pointNext = head;
    head->next = nullptr;
    while(pointNow != nullptr){
        pointNext = pointNow->next;
        pointNow->next = head;
        head = pointNow;
        swap(pointNow, pointNext);
    }
    return head;
} // runtime : 12 ms (faster than 30.58 %), memory usage : 8.3 MB (less than 80.59 %)
// linked list is reversed iteratively



ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next)) return head;

    ListNode* pointNode = reverseList(head->next);
    (head->next)->next = head;
    head->next = nullptr;
    return pointNode;
} // runtime : 4 ms (faster than 94.30 %), memory usage : 8.5 MB (less than 20.34 %)
// linked list is reversed recursively
