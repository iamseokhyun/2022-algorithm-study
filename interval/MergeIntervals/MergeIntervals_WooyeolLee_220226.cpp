#include <algorithm>

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n == 1) return intervals;

    sort(intervals.begin(), intervals.end());
    
    vector<int> start_idx;
    start_idx.push_back(0);
    for(int i=1;i<n;i++)
        if(intervals[start_idx.back()][1] >= intervals[i][0])
            intervals[start_idx.back()][1] = max(intervals[i][1], intervals[start_idx.back()][1]);
        else
            start_idx.push_back(i);
        
    int cnt = 0;
    while(!start_idx.empty()){
        intervals.erase(intervals.begin()+start_idx.back() + 1, intervals.end() - cnt++);
        start_idx.pop_back();
    }
    return intervals;
} // runtime : 28 ms (faster than 94.95 %), memory usage : 18.7 MB (less than 92.88 %)
