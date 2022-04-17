ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *pointNode = head, *pointDelayedNode = head;
    while(n--) pointNode = pointNode->next;
        
    if(pointNode == nullptr) return head->next;
    while(pointNode->next != nullptr){
        pointNode = pointNode->next;
        pointDelayedNode = pointDelayedNode->next;
    }
    pointDelayedNode->next = (pointDelayedNode->next)->next;
        
    return head;
} // runtime : 4 ms (faster than 79.31 %), memory usage : 10.8 MB (less than 33.67 %)
