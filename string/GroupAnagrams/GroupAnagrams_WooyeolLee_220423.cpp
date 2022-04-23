vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
       
    for(string str : strs){
        string temp = str;
        sort(temp.begin(), temp.end());
        map[temp].push_back(str);
    }
        
    vector<vector<string>> anagrams_group;
    for(auto anagrams : map)
        anagrams_group.push_back(anagrams.second);
    return anagrams_group;
} // runtime : 39 ms (faster than 76.54 %), memory usage : 20.5 MB (less than 57.83 %)

/*
- unordered_map **map** contains groups of strings which are anagrams each other. 
string **temp** is a representative string for an anagram group.
- After grouping the anagrams, change the container of anagram groups from unordered_map to 2-D vector.
*/
