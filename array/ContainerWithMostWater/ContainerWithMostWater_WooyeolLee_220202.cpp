 int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int max_water = 0;
        
    do{
        bool MaxValue = true;
        if(height[left] < height[right]){
            max_water = max(max_water, height[left]*(right-left));
            for(int i=1;i<right-left;i++)
                if(height[left] < height[left + i]){
                    left += i;
                    MaxValue = false;
                    break;
                }
        }
        else{
            max_water = max(max_water, height[right]*(right-left));
            for(int i=1;i<right-left;i++)
                if(height[right] < height[right-i]){
                    right -= i;
                    MaxValue = false;
                    break;
                }
        }
        if(MaxValue) break;
    }while(left < right);
    return max_water;
}
