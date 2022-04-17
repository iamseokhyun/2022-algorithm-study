// algorithm using stack
#include <stack>

void reorderList(ListNode* head) {
    if(!(head->next)) return;
        
    ListNode* pointNode = head->next;
    stack<ListNode*> NodeStack;
    while(pointNode){
        NodeStack.push(pointNode);
        pointNode = pointNode->next;
    }
        
    pointNode = head;

    while(pointNode != pointNode->next && pointNode != NodeStack.top()){
        ListNode* elem = NodeStack.top();
        NodeStack.pop();
        elem->next = pointNode->next;
        pointNode->next = elem;
        pointNode = elem->next;
    }
    pointNode->next = nullptr;
} // runtime : 54 ms (faster than 59.95 %), memory usage : 18.6 MB (less than 23.60 %)



// algorithm using deque
#include <deque>

void connectNode(ListNode* pointNode, deque<ListNode*>& NodeSet, bool popFront){
    if(NodeSet.empty()){
        pointNode->next = nullptr;
        return;
    }
        
    ListNode* elem;
    if(popFront){
        elem = NodeSet.front();
        NodeSet.pop_front();
        pointNode->next = elem;
    }
    else{
        elem = NodeSet.back();
        NodeSet.pop_back();
        pointNode->next = elem;
    }
    connectNode(elem, NodeSet, !popFront
}
void reorderList(ListNode* head) {
    if(!(head->next)) return;
    
    ListNode* pointNode = head->next;
    deque<ListNode*> NodeSet;
    while(pointNode){
        NodeSet.push_back(pointNode);
        pointNode = pointNode->next;
    }
       
    pointNode = head;
    connectNode(pointNode, NodeSet, false);
} // runtime : 56 ms (faster than 56.42 %), memory usage : 18.6 MB (less than 23.60 %)
