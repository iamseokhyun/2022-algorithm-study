/* 1. algorithm using sorting
  runtime : 27 ms, memory usage : 7.2 MB
  
  Definition of Anagram : a word or phrase formed by rearranging the letters of 
  a different word or phrase, typically using all the original letters exactly once.
  →by definition, we can tell string t is an anagram of string s if strings after sorting are same.
*/

#include <algorithm>

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
        
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}



/* 2. algorithm using HashTable
  runtime : 13 ms, memory usage : 7.2 MB

  also by definition of Anagram, we can tell string t is an anagram of string s 
  if string s, t have same character components.
*/

#include <unordered_map>

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
        
    unordered_map<char, int> dict;
    for(char c : s) dict[c]++;
    for(char c : t) dict[c]--;
       
    for(auto elem : dict)
        if(elem.second) return false;
    return true;
}
