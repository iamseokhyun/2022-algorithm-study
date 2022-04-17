int findMinIndex(vector<int>& nums) {
    int low = 0;
    int high = nums.size();
    while(low < high){
        int mid = (low + high) / 2;
        if(nums[low] < nums[mid])
            low = mid;
        else
            high = mid;
    }
    return (low+1)%nums.size();
} // from problem 'Find Minimum in Rotated Sorted Array'

int search(vector<int>& nums, int target) {     
    int MinIndex = findMinIndex(nums);
        
    int n = nums.size();
    int low = 0, high = n-1;	
    while(low <= high){
        int mid = (low + high) / 2;		// low, high, mid는 원소의 크기 순번임
        int MiddleIndex = (MinIndex + mid)%n; 	// 크기 순서에서 index 값으로 변환
        if(nums[MiddleIndex] == target)
            return MiddleIndex;
        if(nums[MiddleIndex] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;       	// while loop을 빠져나온 경우는 target을 만족하는 원소가 없는 경우
}
