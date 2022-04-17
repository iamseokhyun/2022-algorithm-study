vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    if(nums.size() < 3) return ans;
        
    unordered_map<int,vector<int>> numsMap;
    for(int i=0;i<n;i++)
        numsMap[nums[i]].push_back(i);
        
    for(auto firstElem = numsMap.begin(); firstElem != numsMap.end(); firstElem++)
        for(auto secondElem = firstElem; secondElem != numsMap.end(); secondElem++){
            if(firstElem != secondElem || firstElem->second.size() != 1){
                if(firstElem->first == 0 && secondElem->first == 0){
                    if(firstElem ->second.size() > 2) 
                        ans.push_back({0,0,0});
                }
                else{
                    auto thirdElem = numsMap.find(-(firstElem->first) -(secondElem->first));
                    if(thirdElem != numsMap.end() && (firstElem != thirdElem || firstElem -> second.size() != 1)
                      && (secondElem != thirdElem || secondElem -> second.size() != 1)){
                        vector<int> temp = {firstElem->first, secondElem->first, thirdElem->first};
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);
                    }
                }
            }
        }
        
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
    return ans;
} // runtime 312 ms(faster than 18.97 %), memory usage 31.7 MB(less than 12.63 %)


// algorithm using HashTable
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    if(nums.size() < 3) return ans;
        
    unordered_map<int,vector<int>> numsMap;
    for(int i=0;i<n;i++)
        numsMap[nums[i]].push_back(i);
        
    for(auto firstElem = numsMap.begin(); firstElem != numsMap.end(); firstElem++){
        int temp1 = firstElem->second.back();
        firstElem->second.pop_back();
        
        for(auto secondElem = numsMap.begin(); secondElem != numsMap.end(); secondElem++){
            if(!secondElem->second.empty() && firstElem->first <= secondElem->first){
                int temp2 = secondElem->second.back();
                secondElem->second.pop_back();
                
                auto thirdElem = numsMap.find(-(firstElem->first) -(secondElem->first));
                if(thirdElem != numsMap.end() && !thirdElem->second.empty() && secondElem->first <= thirdElem->first){
                    vector<int> temp = {firstElem->first, secondElem->first, thirdElem->first};
                    ans.push_back(temp);
                }
                secondElem->second.push_back(temp2);
            }
        }
        firstElem->second.push_back(temp1);
    }
        
    return ans;
} // runtime 562 ms(faster than 14.07 %), memory usage 22.6 MB(less than 32.86 %)
