vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix_prod(n);
    vector<int> suffix_prod(n);
        
    prefix_prod[0] = 1;
    suffix_prod[n-1] = 1;
    for(int i=1;i<n;i++){
        prefix_prod[i] = prefix_prod[i-1]*nums[i-1];
        suffix_prod[n-1-i] = suffix_prod[n-i]*nums[n-i];
    }
        
    vector<int> ans(n);
    for(int i=0;i<n;i++)
        ans[i] = prefix_prod[i]*suffix_prod2[i];
       
    return ans;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++)
        ans[i] = ans[i-1]*nums[i-1];
    for(int i=n-2;i>-1;i--){
        nums[i] = nums[i]*nums[i+1];
        ans[i] = ans[i]*nums[i+1];
    }
    return ans;
}
