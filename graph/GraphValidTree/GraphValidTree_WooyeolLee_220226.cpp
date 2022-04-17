// Algorithm 1
#include <algorithm>
#include <list>

struct Node{
    vector<list<int>> connected;
    vector<bool> visited;
    Node(int n) : connected(n), visited(n, false){};

    void DFS(int vertexNum, bool& isTree){
        visited[vertexNum] = true;

        while(!connected[vertexNum].empty()){
            int there = connected[vertexNum].front();
            if(!visited[there]){
                auto it = find(connected[there].begin(), connected[there].end(), vertexNum);
                connected[there].erase(it);
                DFS(there, isTree);
            }
            else isTree = false;

            if(!isTree) break;
            connected[vertexNum].pop_front();
        }
    } // connected의 삭제가 빈번하므로 list container 사용
};

bool validTree(int n, vector<vector<int>> &edges) {
    if(n==1) return true; // n=1인 경우는 무조건 valid tree 임

    Node Vertices(n);
    // Make Graph
    for(auto edge : edges){
        Vertices.connected[edge[0]].push_back(edge[1]);
        Vertices.connected[edge[1]].push_back(edge[0]);
    }

    // DFS
    bool isTree = true;
    Vertices.DFS(0, isTree);
       
    if(!isTree) return false; // 탐색이 중복된다는 것은 cycle이 존재한다는 뜻임
    for(int i=0;i<n;i++)
        if(!Vertices.visited[i]) // nodes가 두 부분으로 나뉜 경우(forest인 경우)
            return false;
    return true;
} // runtime : 711 ms, memory usage : 5.67 MB (by LintCode) / TC : O(n), SC : O(n)




// Algorithm 2
struct Node{
    vector<int> parent;
    vector<int> rank;
    vector<bool> isConnected;
    Node(int n) : parent(n), rank(n,0), isConnected(n){
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
    void Union(int x, int y, bool& isTree){
        isConnected[x] = isConnected[y] = true;

        x = Find(x);
        y = Find(y);
           
        if(x == y){
            isTree = false;
            return;
        }

        if(rank[x] < rank[y])
            swap(x,y);
            
        parent[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
    }
};

bool validTree(int n, vector<vector<int>> &edges) {
    if(n==1) return true; // n=1인 경우는 무조건 valid tree 임
    Node Set(n);

    bool isTree = true;
    for(auto edge : edges){
        Set.Union(edge[0], edge[1], isTree);
        if(!isTree) return isTree;
    }
		
    int rootNode = Set.Find(0);
    for(int i=0;i<n;i++)
        if(!Set.isConnected[i] || rootNode != Set.Find(i)) 
            return isTree = false; // vertices가 연결되어 있지 않으면 valid tree 불가

return isTree;        
} // runtime : 729 ms, memory usage : 5.52 MB (by LintCode) / TC : O(n), SC : O(n)
 
