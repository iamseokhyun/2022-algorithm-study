// brute-force way, O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for(int i=0;i<nums.size()-1;i++)
        for(int j=i+1;j<nums.size();j++)
            if(nums[i]+nums[j] == target){
                ans = {i,j};
                break;
            }
    return ans;
}

// two sum using HashTable, O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> numsMap;
    for(int i=0;i<nums.size();i++)		
        numsMap[nums[i]].push_back(i);
    
    vector<int> ans;
    for(auto elem = numsMap.begin(); elem != numsMap.end(); elem++){
        auto check = numsMap.find(target - elem->first);		
        if(check != numsMap.end() && (elem != check || elem -> second.size() == 2)){	
            ans.push_back(elem -> second[0]);
            elem -> second.erase(elem->second.begin());		
            ans.push_back(check -> second[0]);
            break;
        }
    }
    return ans;
}
