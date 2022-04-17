// Algorithm using iteration
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr || list1->val > list2->val)
        return mergeTwoLists(list2, list1);
        
    ListNode *head = list1, *tail = list1;
    list1 = list1->next;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val > list2->val){
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        else{
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
    }
    if(list1 == nullptr) tail->next = list2;
    else tail->next = list1;
       
    return head;
} // runtime : 7 ms (faster than 83.67 %), memory usage : 14.7 MB (less than 82.99 %)


// Algorithm using recursion
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr)
        return mergeTwoLists(list2, list1);
        
    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
} // runtime : 8 ms (faster than 77.61 %), memory usage : 14.8 MB (less than 83.02 %)
