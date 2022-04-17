int maxSubArray(vector<int>& nums) {
    for(int i=1;i<nums.size();i++)
        nums[i]+= nums[i-1];		// prefix sum으로 nums 재정의
        
    int low = 0;			// i = 0 인 경우를 고려하기 위함
    int ans = nums[0];
    for(int i=0;i<nums.size();i++){
        ans = max(ans, nums[i]-low);
        low = min(low, nums[i]);
    }
    return ans;
}

// follow-up question (using divide&conquer)
vector<int> prefix, suffix;
int maxSubArray(vector<int>& nums) {
    prefix = suffix = nums;
    for(int i=1;i<nums.size();i++)
        prefix[i] += max(0, prefix[i-1]);
    for(int i = nums.size()-2;i>-1;i--)
        suffix[i] += max(0, suffix[i+1]);
        
    return maxDivConquer(nums, 0, nums.size()-1);
}
int maxDivConquer(vector<int>& nums, int left, int right){
    if(left == right) return nums[left];
    int mid = (left + right)/2;
    return max({maxDivConquer(nums, left, mid), maxDivConquer(nums, mid+1, right), 
        prefix[mid] + suffix[mid+1]});
}
