#include <unordered_map>
using namespace std;

struct Node{
    Node* parent;
    int rank = 0;
};
    
// this can be decreased to a constant amount memory
// by performing both passes in the same direction
// two passes - once to find the root, once to update pointers.
Node* Find(Node* x){
    Node* root = x;
    while(root->parent != root)
        root = root->parent;
     
    while(x->parent != root){
        Node* parent = x->parent;
        x->parent = root;
        x = parent;
    }
    return root;
}
    
// union by rank - ensure that trees do not become too deep
void Union(Node* x, Node* y){
    x = Find(x);
    y = Find(y);
        
    if(x == y) return;
      
    if(x->rank < y->rank){
        Node* temp = y;
        y = x;
        x = temp;
    }
        
    y->parent = x;
    if(x->rank == y->rank)
        x->rank += 1;
}     
    
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
      
    Node** GridNode = new struct Node*[m];  // (1)
    for(int i=0;i<m;i++)
        GridNode[i] = new struct Node[n];
    
    // (2) MakeSet Func.    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            GridNode[i][j].parent = GridNode[i] + j;
        
    // (3) connect island (by Union Func.)
    for(int i=0;i<m;i++)
        for(int j=0;j<n-1;j++)
            if(grid[i][j] == '1' && grid[i][j+1] == '1')
                Union(GridNode[i]+j, GridNode[i]+j+1);
      
    for(int i=0;i<m-1;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j] == '1' && grid[i+1][j] == '1')
                Union(GridNode[i]+j, GridNode[i+1]+j);
        
    // (4)
    unordered_map<Node*, int> ans;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j] == '1')
                ans[Find(GridNode[i]+j)]++;
      
    return ans.size();
} // runtime: 39 ms (faster than 68.50 %), memory usage: 16 MB (less than 23.81 %)
