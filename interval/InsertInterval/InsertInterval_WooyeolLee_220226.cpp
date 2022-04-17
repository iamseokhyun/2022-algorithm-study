int binSearch(vector<vector<int>>& intervals, int new_val, int low, int high){
    if(low == high) return low;        
    int mid = (low + high) / 2;
       
    if(intervals[mid >> 1][mid & 1] > new_val)
        return binSearch(intervals, new_val, low, mid);
    else
        return binSearch(intervals, new_val, mid+1, high);
} // low -1 <= new_val < low 의 위치를 리턴함
    
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    if(!n){
        intervals.push_back({newInterval}); 
        return intervals;
    } // intervals가 비어있는 경우 처리
    
    // intervals(1차원 vector로 생각)에서 newInterval[i]가 들어갈 위치 이진탐색
    int pos1 = binSearch(intervals, newInterval[0], 0, 2*n);
    int pos2 = binSearch(intervals, newInterval[1], 0, 2*n);
       
    // intervals와 겹치는 newInterval 구간을 newInterval에 덮어씌움
    if(!(pos1 & 1)){
        if(pos1 > 0 && intervals[(pos1-1) >> 1][1] == newInterval[0]){
            newInterval[0] = intervals[(pos1-1) >> 1][0];
            pos1--; // 겹치는 intervals의 시작 위치 재설정
        }
    }
    else    
        newInterval[0] = intervals[(pos1-1) >> 1][0];
        
    if(pos2 & 1) 
        newInterval[1] = intervals[pos2 >> 1][1];
 
    // intervals와 newInterval의 겹치는 interval을 제거한 후 수정한 newInterval을 insert
    intervals.erase(intervals.begin() + (pos1 >> 1), intervals.begin() + ((pos2+1) >> 1));
    intervals.insert(intervals.begin() + (pos1 >> 1), {newInterval});

    return intervals;
} // runtime : 16 ms (faster than 81.47 %), memory usage : 41.27 MB (less than 41.27 %)	
