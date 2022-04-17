bool canJump(vector<int>& nums){
    int n = nums.size();
    vector<bool> cache(n);

    cache[n-1] = true; 		// 마지막 index에 도달 -> true
    for(int i = n-2; i>-1; i--)
        for(int j = 1; j<=nums[i];j++)
            if(cache[i+j] == true){
                cache[i] = true;
                break;
            }
    return cache[0];
} // TC : O(nm) (n: nums.length, m: max(nums[i]))

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return true;
        
    vector<bool> can_jump(n-1,true); // true는 탐색하지 않은 경우(default임)
    int curr = 0;
    do{
        if(curr+nums[curr] >= n-1) return true;
        if(nums[curr] == 0 || !can_jump[curr+nums[curr]])
            can_jump[curr--] = false;
        else if(can_jump[curr+nums[curr]]) curr += nums[curr];
    }while(curr > 0);
    return false;
} // runtime : 68 ms (faster than 80.59 %), memory usage : 48.7 MB (less than 16.75 %)



// reference from Leetcode Discussion (TC : O(n), SC : O(1))
bool canJump(vector<int>& nums) {
    int n = nums.size();
        
    int reach = 0;
    for(int curr = 0; curr <= reach && curr<n;curr++){
        reach = max(reach, curr + nums[curr]);
        if(reach >= n-1) return true;
    }
    return false;
} // runtime : 56 ms (faster than 93.69 %), memory usage : 48.3 MB (less than 86.05 %)
