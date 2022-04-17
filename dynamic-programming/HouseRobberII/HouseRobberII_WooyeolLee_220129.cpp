class Solution {
	int sub_rob(vector<int>& nums, int start, int end){ // nums[start ... end-1]ø° ¥Î«— house robber
    	vector<int> cache(2);
        for(int i=start;i<end;i++)
    	    cache[i&1] = max(cache[(i-2)&1] + nums[i], cache[(i-1)&1]);
         
    	return cache[(end-1)&1];
	}
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else
            return max(sub_rob(nums, 1, nums.size()), sub_rob(nums, 0, nums.size()-1));
    }
};
