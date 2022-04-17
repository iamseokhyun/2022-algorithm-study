#include <algorithm>

bool canAttendMeetings(vector<vector<int>>& intervals){
    int n = intervals.size();
    if(!n) return true; // intervalÀÌ ºñ¾îÀÖ´Â °æ¿ì Ã³¸®
    
    sort(intervals.begin(), intervals.end());
    
    for(int i=1;i<n;i++)
        if(intervals[i-1][1] > intervals[i][0])
            return false;
    
    return true;
} // runtime : 61 ms, memory usage : 5.52 MB (by LintCode)
