// Depth First Search & Recursion
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
        
    TreeNode* temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = temp;
    return root;
}
