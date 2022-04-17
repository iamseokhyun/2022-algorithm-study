int cache[1001];
std::fill_n(cache, 1001, -1);
cache[0] = 1;

int combinationSum4(vector<int>& nums, int target){
    if(target<0) return 0;
    
    int& ret = cache[target];
    if(ret != -1) return ret;			// 메모이제이션 적용

    ret = 0;
    for(int i=0;i<nums.size();i++)
        ret += combinationSum4(nums, target - nums[i]);
    return ret;
} // top-down approach

>> run combinationSum4(nums, target)

int combinationSum4(vector<int>&nums, int target){
    vector<uint32_t> cache(target+1);
    cache[0] = 1;

    for(int i=1;i<=target;i++)
        for(int j=0;j<nums.size();j++)
            if(i-nums[j] >= 0)
                cache[i] += cache[i-nums[j]];
    return cache[target];
} // bottom-up approach
