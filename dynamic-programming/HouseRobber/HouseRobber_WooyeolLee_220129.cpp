// top-down approach

vector<int> cache(nums.size(), -1);

int houseRobber(vector<int>& nums, int pos, vector<int>& cache){
    int n = nums.size();
    if(pos == n)		// 남은 원소가 3개일 때 경계조건
        return 0;
     
    int& ret = cache[pos];
    if(ret != -1)
        return ret;
        
    if(pos == n-1)		// 남은 원소가 1개일 때 경계조건
        return ret = nums[pos];
    if(pos == n-2)		// 남은 원소가 2개일 때 경계조건
        return ret = max(nums[pos], nums[pos+1];
    
    if(nums[pos] >= nums[pos+1])
        ret = nums[pos] + houseRobber(nums,pos+2, cache);
    else
        ret = max(nums[pos] + houseRobber(nums, pos+2, cache), 
        		nums[pos+1] + houseRobber(nums, pos+3, cache));
    return ret;
}

>> run houseRobber(nums, 0, cache);



// bottom-up approach

int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    else{
        vector<int> cache(2); // 두 개의 result만 동시에 저장하고 있으면 되므로
        for(int i=0;i<nums.size();i++)
            cache[i&1] = max(cache[(i-2)&1] + nums[i], cache[(i-1)&1]);
            
        return cache[(nums.size()-1)&1];
    }
}
