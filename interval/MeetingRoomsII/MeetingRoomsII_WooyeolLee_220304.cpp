#include <algorithm>

struct EndPoint{
    int pointVal;
    bool isStart = false;
};

static bool cmp(EndPoint p1, EndPoint p2){
    if(p1.pointVal == p2.pointVal){
        if(p1.isStart) return false;
        if(p2.isStart) return true;
    }
    return p1.pointVal < p2.pointVal;
}

int minMeetingRooms(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if(n == 1) return 1;

    EndPoint* PointSet = new struct EndPoint[2*n];

    for(int i=0;i<n;i++){
        PointSet[2*i].pointVal = intervals[i][0];
        PointSet[2*i].isStart = true;
        PointSet[2*i+1].pointVal = intervals[i][1];
        // PointSet[2*i+1].isStart = false; : default
    }
    sort(PointSet, PointSet+2*n, cmp);

    int maxRooms = 0, roomCount = 0;
    for(int i=0;i<2*n;i++){
        if(PointSet[i].isStart)
            maxRooms = max(maxRooms, ++roomCount);
        else --roomCount;
    }
    return maxRooms;
} // runtime : 41 ms, memory usage : 4.68 MB (by LintCode)
