class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        
        nums_one = nums[:len(nums)-1]
        nums_two = nums[1:]
        
        dp = {}
        dp_t = {}
        
        dp[0], dp[1] = nums_one[0], max(nums_one[0], nums_one[1])
        dp_t[0], dp_t[1] = nums_two[0], max(nums_two[0], nums_two[1])
        
        
        for i in range(2, len(nums_one)):
            dp[i] = max(dp[i-1], dp[i-2] + nums_one[i])
            dp_t[i] = max(dp_t[i-1], dp_t[i-2] + nums_two[i])
            
        return max(dp.popitem()[1], dp_t.popitem()[1])
