int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n*(n+1)/2;
    int sum = 0;
    for(int i=0;i<n;i++){
    	sum += nums[i];
    }
    return total - sum;
}

// idea from Gauss Summation !
int missingNumber(vector<int>& nums) {
    int missing_xor = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        missing_xor = missing_xor^nums[i];		// nums 원소에 대한 xor 계산
    }
        
    int correct_xor;
    switch(n % 4){					// 0 ~ n에 대한 xor 값 대입
        case 0:
            correct_xor = n; break;
        case 1:
            correct_xor = 1; break;
        case 2:
            correct_xor = n+1; break;
        case 3:
            correct_xor = 0; break;
    }
        
    return missing_xor^correct_xor;	
}
