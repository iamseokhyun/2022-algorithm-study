int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
        
    int max_product = 0;  // n > 1인 경우 max_product의 최솟값은 0임
    int left = 0, right = 1; // left: 0 기준으로 나눈 영역의 맨 왼쪽 index
	                     // right: 영역을 탐색하는 역할
    
    vector<int> negativeIndex;
    if(nums[0] < 0) negativeIndex.push_back(0); // index 0에 대해 먼저 고려(while문때문)
    else if(nums[0] == 0) left = 1;
    
    while(right < n){
        while(right < n && nums[right] != 0){  // right로 영역 탐색
            if(nums[right] < 0)
                negativeIndex.push_back(right); // 음수 index 저장
            if(nums[right-1])  // nums[right]의 탐색(0, 음수값)을 방해하지 않도록 prefix product 동시 진행
                nums[right] = nums[right]*nums[right-1];  // prefix product 적용
            right++;
        } // while 문을 마치면 영역의 마지막+1의 위치를 가리킴(vec.end()와 같음)
            
        if(negativeIndex.size() & 1 && right-left > 1){ // 영역에 포함된 원소가 1개인 경우는 제외
            if(negativeIndex.back() > left) // negativeIndex.back()이 영역의 맨 왼쪽에 있는 경우 고려
                max_product = max(max_product, nums[negativeIndex.back()-1]);
            max_product = max(max_product, nums[right-1] / nums[negativeIndex.front()]);
        }
        else
            max_product = max(max_product, nums[right-1]);
            
        left = ++right;
        negativeIndex.clear();
    }
      
    return max_product;
}

// reference from leetcode discussion.
// Far simple code
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
        
    int max_val = 1, min_val = 1;
    int max_product = 0;
    for(int i=0;i<n;i++){
        if(nums[i] < 0)
            swap(max_val, min_val);
        max_val = max(nums[i], max_val*nums[i]);
        min_val = min(nums[i], min_val*nums[i]);
        max_product = max(max_product, max_val);
    }
    return max_product;
}
