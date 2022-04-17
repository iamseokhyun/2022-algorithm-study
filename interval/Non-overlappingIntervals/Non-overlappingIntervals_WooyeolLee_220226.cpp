#include <algorithm>

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
        
    int can_end = 123456, ans_cnt = 0;
    for(int i=n-1;i>-1;i--){
        if(intervals[i][1] <= can_end)
            can_end = intervals[i][0];
        else
            ans_cnt++;
    }
    return ans_cnt;
} // runtime : 505 ms (faster than 71.07 %), memory usage : 89.9 MB (less than 47.54 %)
