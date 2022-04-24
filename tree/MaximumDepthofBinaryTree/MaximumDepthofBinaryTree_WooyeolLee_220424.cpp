// Depth-First-Search on tree node

int DFS(TreeNode* node){
    if(!node) return 0;
    else if(!node->left && !node->right) return 1;
    return 1 + max(DFS(node->left), DFS(node->right));
}
int maxDepth(TreeNode* root) {
    return DFS(root);
} // runtime : 12 ms (faster than 53.79 %), memory usage : 18.7 MB (less than 89.91 %)
