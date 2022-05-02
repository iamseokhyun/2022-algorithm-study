#include <queue>
#include <algorithm>

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if(root == nullptr) return ret;
    
    // initialize queue(nodeSet) with root node    
    queue<TreeNode*> nodeSet;
    nodeSet.push(root);
    ret.push_back({});
    // curr_depth_elem and next_depth_elem indicate the number of nodes in current depth and current+1(next) depth respectively
    int curr_depth = 0, curr_depth_elem = 1, next_depth_elem = 0;
        
    while(!nodeSet.empty()){
        TreeNode* current = nodeSet.front();
        nodeSet.pop();
            
        // look up for children nodes
        if(current->left){
            nodeSet.push(current->left);
            next_depth_elem++;
        }
        if(current->right){
            nodeSet.push(current->right);
            next_depth_elem++;
        }
        
        // save value of node at its depth group
        ret[curr_depth].push_back(current->val);
        // grouping nodes by theirs depth
        if(!--curr_depth_elem && next_depth_elem){
            curr_depth++;
            ret.push_back({});
            swap(curr_depth_elem, next_depth_elem);  
        }
    }
        
    return ret;
} // runtime : 6 ms (faster than 50.57 %), memory usage : 12.4 MB (less than 85.00 %)

/*
- To return *the level order traversal of its nodes’ values* I used queue container to implement Breath-First-Search.
- Another challenge is that I have to group nodes by its depth. By saving how many nodes are at current depth and next depth, I can meet this need.
- let n = the number of nodes in the tree, then
  Time complexity : O(n), Space complexity: O(n) (=maximum number of nodes in single depth = maximum number of leaf nodes = (n+1)/2)
*/
