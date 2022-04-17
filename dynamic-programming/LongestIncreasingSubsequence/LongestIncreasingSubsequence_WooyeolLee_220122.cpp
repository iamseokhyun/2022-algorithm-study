// TC : O(n^2)
int cache[2501];
std::fill_n(cache, 2501, -1);		// 값이 할당되지 않은 경우를 나타내는 -1로 초기화

int lengthOfLIS(vector<int>& nums, int start){
    int& ret = cache[start+1];
    if(ret != -1) return ret;

    ret = 0;
    for(int next=start+1;next<nums.size();next++)
        if(start == -1 || nums[start] < nums[next])
            ret = max(ret, lengthOfLIS(nums, next)+1);
    return ret;
}

>> run lengthOfLIS(nums, -1)		// 가상의 index -1에서 시작하는 search



// TC : O(n log n)
void binsearch(vector<int>& A, int low, int high, int target){
    while(low < high){
        int mid = (low + high)/2;
        if(A[mid] < target) low = mid+1;
        else high = mid;
    }
        A[low] = target;
} // 이진 탐색으로 cache값을 업데이트 하는 함수

int lengthOfLIS(vector<int>& nums) {
    vector<int> cache;
    cache.push_back(nums[0]);
     
    for(int i=1;i<nums.size();i++){
        if(cache.back() > nums[i])
            cache.push_back(nums[i]);
        else
            binsearch(cache, 0, cache.size()-1, nums[i]);
    }
    return cache.size();			// cache의 크기가 곧 LIS의 길이
} // O(n log n) time complexity
