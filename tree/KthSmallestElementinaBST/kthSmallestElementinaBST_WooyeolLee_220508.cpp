#include <list>

int kthSmallest(TreeNode* root, int k) {
    list<int> sorted;
    sorted.push_back(root->val);
    insertNodeVal(root, sorted, sorted.begin());
        
    auto ret = sorted.begin();
    while(--k != 0) ret++;
    return *ret;
}
void insertNodeVal(TreeNode* root, list<int>& sorted, list<int>::iterator it){
    auto copy = it;
    if(root->left != nullptr){
        copy = sorted.insert(copy, root->left->val);
        insertNodeVal(root->left, sorted, copy);
    }
    if(root->right != nullptr){
        it = sorted.insert(++it, root->right->val);
        insertNodeVal(root->right, sorted, it);
    }
    return;
} // runtime : 27 ms (faster than 23.30 %), memory usage : 25.5 MB (less than 17.09 %)

/*
- make a sorted list of nodes’ value and find kth element(=kth smallest element)
- This algorithm is slow for finding the kth smallest element just few times. 
  However, *if the BST is modified often(i.e. we can do insert and delete operations) 
  and you need to find the kth smallest frequently*, this algorithm will be useful.
*/




int kthSmallest(TreeNode* root, int k) {
    int ret = NULL;
    inorderTvsl(root, ret, k);
    return ret;
}
void inorderTvsl(TreeNode* root, int& target, int& k){
    if(!root) return;
    inorderTvsl(root->left, target, k);
    if(--k == 0){
        target = root->val;
        return;
    }
    inorderTvsl(root->right, target, k);
} // runtime : 16 ms (faster than 82.52 %), memory usage : 24.1 MB (less than 88.29 %)

/*
- Algorithm using “inorder traversal”. 
This algorithm is useful only if we find kth smallest element few times.
*/
