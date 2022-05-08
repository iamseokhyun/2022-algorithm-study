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
