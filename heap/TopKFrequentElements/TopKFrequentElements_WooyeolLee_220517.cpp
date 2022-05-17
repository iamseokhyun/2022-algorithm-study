#include <unordered_map>

static bool cmp(pair<int,int>& p1, pair<int,int>& p2){    
    return p1.second < p2.second;    
}    
vector<int> topKFrequent(vector<int>& nums, int k) {    
    unordered_map<int,int> numElem;    
    for(int num : nums) numElem[num]++;        
    
    vector<pair<int,int>> heap;    
    for(auto elem : numElem)        
        heap.push_back(elem);    
    make_heap(heap.begin(), heap.end(), cmp);        

    vector<int> ret;    
    while(k-- != 0){    
        pop_heap(heap.begin(), heap.end(), cmp);    
        ret.push_back(heap.back().first);    
        heap.pop_back();    
    }    
    return ret;    
} // runtime : 8 ms (faster than 99.29 %), memory usage : 13.6 MB (less than 72.30 %)

/*
- HashTable type numElem object : count the number each element appears
- vector type heap object : move element informations from hash table 
  to random accessible container(vector container), which can be used as heap structure.
- Compare function cmp : make it possible to build heap structure in frequency of element order.
- Time complexity : O(n)(hash table) + O(n)(container change, hash table → vector) 
  + O(n)(make heap) + k*O(log n) (pop heap: pop top element & rebuilding heap) ≤ O(n log n)
- Space complexity : O(n)(hash table) + O(n)(vector) = O(n)
*/
