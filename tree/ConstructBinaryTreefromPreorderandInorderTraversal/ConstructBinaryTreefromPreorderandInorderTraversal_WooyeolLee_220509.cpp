#include <unordered_map>

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inorderIdx;
    for(int i=0;i<inorder.size();i++)
        inorderIdx[inorder[i]] = i;
        
    TreeNode* root = new struct TreeNode;
    root = connectNode(root, preorder, inorderIdx, 0, preorder.size()-1, 0);
    return root;
}
TreeNode* connectNode(TreeNode* root, vector<int>& preorder, unordered_map<int,int>& inorderIdx, int begin, int end, int numLeftDepth){
    root->val = preorder[begin];
    if(begin == end) return root;
        
    int currIdx = inorderIdx[preorder[begin]]+numLeftDepth;
        
    if(begin+1 <= currIdx){
        TreeNode* left = new struct TreeNode;
        root->left = connectNode(left, preorder, inorderIdx, begin+1, currIdx, numLeftDepth+1);
    }
    if(currIdx+1 <= end){    
        TreeNode* right = new struct TreeNode;
        root->right = connectNode(right, preorder, inorderIdx, currIdx+1, end, numLeftDepth);
    }
            
    return root;
} // TIME LIMIT EXCEED for test case of size 3000 (202 th test case / 203)
  // -> runtime : 16 ms (faster than 87.31 %), memory usage : 26.3 MB (less than 57.25 %) after revision.

/*
- What’s the problem ?
→ In declaration of the function “TreeNode* connectNode”, ... unordered_map<int, int> inorderIdx, ... made the Time Limit Exceed Error. 
  REFERENCE for the unordered_map container is necessary.
- Idea: value in inorder vector corresponding to preorder[0] divides inorder vector into two parts, which is left subtree and right subtree. 
  By using this rule recursively,  we can construct binary tree.
- Complexity Analysis:
    T.C.: O(N) (Building HashTable & Tree)  
    S.C.: O(N)  
    1) Storing HashTable & Tree - O(N)
    2) implicit system stack used by recursion calls depends on height of the tree: O(N) for the worst case, O(log N) for an average.
*/
