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
    
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    Node* Set = new struct Node[n];
    unordered_map<int, int> inverseNums;
        
    // MakeSet func.
    for(int i=0;i<n;i++){
        inverseNums[nums[i]] = i;
        Set[i].parent = Set+i;
    }
        
    for(auto elem : inverseNums){
        auto check = inverseNums.find(elem.first+1);
        if(check != inverseNums.end())
            Union(Set + inverseNums[elem.first], Set + inverseNums[elem.first+1]);
    }
       
    unordered_map<Node*, int> cnt;
    for(auto elem : inverseNums)
        cnt[Find(Set + inverseNums[elem.first])]++;
    
    int ans = 0;
    for(auto elem : cnt)
        ans = max(ans, elem.second);
        
    return ans;
} // runtime 106 ms (faster than 62.70 %), memory usage 33.3 MB (less than 7.58%)
