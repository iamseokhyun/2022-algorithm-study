bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    if(head->next == nullptr) return false;
        
    ListNode EndNode(0), *pointNext = head;
    while(head->next != &EndNode){
        pointNext = head->next;
        head->next = &EndNode;
        head = pointNext;
        if(head->next == NULL) return false;
    }
    return true;
} // runtime : 8 ms (faster than 95.72 %), memory usage : 8 MB (faster than 81.49 %)
  // TC : O(n), SC : O(1)
