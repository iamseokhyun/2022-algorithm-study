// Depth-First-Search & Recursion
bool isSameTree(TreeNode* p, TreeNode* q) {
    if((p == nullptr)^(q == nullptr)) return false; // if only one pointer is nullptr
        
    if(p == nullptr) return true; // if both pointers are nullptr
    else if(p->val != q->val) return false; // if both pointers are not nullptr
        
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
