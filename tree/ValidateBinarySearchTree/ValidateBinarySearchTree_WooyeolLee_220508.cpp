// algorithm ver.1
bool isValidBST(TreeNode* root, long lower = LONG_MIN, long upper = LONG_MAX) {
    bool isValid = true;
        
    if(root->left != nullptr){
        if(root->val > root->left->val && root->left->val > lower)
            isValid = isValidBST(root->left, lower, root->val);
        else return false;
    }
    if(root->right != nullptr){
        if(isValid && root->val < root->right->val && root->right->val < upper)
            isValid = isValidBST(root->right, root->val, upper);
        else return false;
    }
        
    return isValid;
} // runtime : 10 ms (faster than 86.83 %), memory usage : 21.7 MB (less than 71.86 %)

/*
- Check if the binary tree with root node “root” is valid recursively.
  : The left subtree of a node contains only nodes with keys **less than** the node's key.
  : The right subtree of a node contains only nodes with keys **greater than** the node's key.
- LONG_MIN and LONG_MAX provide default bound of node’s value.
*/



// algorithm ver.2
bool isValidBST(TreeNode* root) {    
    TreeNode* prev = nullptr;      
    return validate(root, prev);    
}    
bool validate(TreeNode* root, TreeNode* &prev){    
    if(root == nullptr) return true;    
    if(!validate(root->left, prev)) return false;    
    if(prev != nullptr && prev->val >= root->val) return false;    
    prev = root;    
    return validate(root->right, prev);    
} // runtime : 14 ms (faster than 67.92 %), memory usage : 21.7 MB (less than 33.23 %)

/*
- Solution using “inorder traversal” of binary tree. -> O(N) (Idea from leetcode discussion)
  → neat code compared to algorithm above.
*/
