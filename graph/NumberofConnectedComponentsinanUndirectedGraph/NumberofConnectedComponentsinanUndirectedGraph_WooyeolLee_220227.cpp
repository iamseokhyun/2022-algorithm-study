#include <algorithm>

struct Node{
    vector<int> parent;
    vector<int> rank;
    Node(int n) : parent(n), rank(n,0){
        for(int i=0;i<n;i++) parent[i] = i;
    }
    // this can be decreased to a constant amount memory
    // by performing both passes in the same direction
    // two passes - once to find the root, once to update pointers.
    int Find(int x){
        int root = x;
        while(parent[root] != root)
            root = parent[root];
            
        while(parent[x] != root){
            int temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;            
    }   
    // union by rank - ensure that trees do not become too deep
    void Union(int x, int y, int& count){
        x = Find(x);
        y = Find(y);
         
        if(x == y) return;

        if(rank[x] < rank[y])
            swap(x,y);
            
        parent[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
            
        count--;
    }
};
int countComponents(int n, vector<vector<int>> edges) {
    Node Vertices(n);

    int count = n;
    for(auto edge : edges)
         Vertices.Union(edge[0], edge[1], count);
        
    return count;
}
