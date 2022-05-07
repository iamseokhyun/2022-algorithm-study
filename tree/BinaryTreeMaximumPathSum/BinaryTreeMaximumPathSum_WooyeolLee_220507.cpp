// algorithm ver.1
#include <unordered_map>

unordered_map<TreeNode*, int> maxPath, singlePath;
int maxPathSum(TreeNode* root) {
    if(root == nullptr) return INT_MIN;
        
    if(maxPath[root] != 0) return maxPath[root];
    maxPath[root] = max(maxPathSum(root->left), maxPathSum(root->right));
    maxPath[root] = max(maxPath[root], singlePathSum(root->left)+singlePathSum(root->right)+root->val);
    return maxPath[root];
}
int singlePathSum(TreeNode* root){
    if(root == nullptr) return 0;
      
    if(singlePath[root] != 0) return singlePath[root];
    singlePath[root] = root->val + max(singlePathSum(root->left), singlePathSum(root->right));
    singlePath[root] = max(singlePath[root], 0);
    return singlePath[root];
} // runtime : 168 ms, memory usage : 38.5 MB /* very poor performance :( */

/*
- Maximum path of the node “root” is equal to maximum path among maximum path of root→left, that of root→right, 
  and path from left edge of the tree to right edge of the tree through root node.
- singlePathSum function is calculating maximum “single” path, i.e. path ends at root node.
- To use memoization, I declared maxPath, singlePath(type hashtable<TreeNode*, int>) to save maximum path of each node. 
  But as maxPath and singlePath are initialized to 0 if actual value(maximum path) is 0, algorithm assumes this node has 
  not been visited. This would make the algorithm goes slow.
  → revised the algorithm by using INT_MIN at line 7, 15. But it still makes a poor performance; runtime : 108 ms , memory usage : 38.5 MB.
*/
