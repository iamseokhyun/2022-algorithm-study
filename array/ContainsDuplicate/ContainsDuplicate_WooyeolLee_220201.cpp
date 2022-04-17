#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(), nums.end());
    for(int i=1;i<nums.size();i++)
        if(nums[i] == nums[i-1])
      	    return true;
    return false;
}

#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums){
    unordered_map<int, int> memory;
    
    for(int i=0;i<nums.size();i++){
        if(memory[nums[i]])
            return true;
        memory[nums[i]]++;
    }
    return false;
}
