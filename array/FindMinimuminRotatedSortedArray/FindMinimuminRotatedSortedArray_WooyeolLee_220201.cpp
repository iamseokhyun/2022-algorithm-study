int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size();

    while(low < high){
        int mid = (low + high) / 2;
        if(nums[low] < nums[mid])
            low = mid;
        else
            high = mid;
    }
    return nums[(low+1)%nums.size()];
}
