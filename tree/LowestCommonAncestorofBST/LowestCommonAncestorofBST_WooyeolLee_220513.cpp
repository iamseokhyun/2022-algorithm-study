TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val == p->val || root->val == q->val) return root;
    if(root->val > q->val && root->val > p->val) 
        return lowestCommonAncestor(root->left, p, q);
    if(root->val < p->val && root->val < q->val) 
        return lowestCommonAncestor(root->right, p, q);
    return root;
} // runtime : 39 ms, memory usage : 23.2 MB

/*
- By using definition of BST, we can narrow down candidates of LCA (divde by two).
- Time complexity is determined by the number LCA function is called, which is maximum the height of the BST(= O(H) = O(log N)).
Space complexity is also determined by recursion stack memory, which is maximum the height of the BST(= O(H) = O(log N)).
*/
