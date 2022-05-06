bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p^!q) return false; // if only one pointer is nullptr
    if(!p) return true; // if both pointers are nullptr
    else if(p->val != q->val) return false; // if both pointers are not nullptr
        
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return false;
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
} // runtime : 25 ms (faster than 76.71 %), memory usage : 28.9 MB (less than 56.67 %)

/*
- used algorithm from [Same Tree]
- During tree traversal, checking if the trees whose root nodes are root & subRoot respectively are the same tree. 
  If the algorithm find subRoot tree is a subtree of root tree, it stops tree traversal and return true. 
  If it does not find subtree relationship through tree traversal, however, return false.
*/
