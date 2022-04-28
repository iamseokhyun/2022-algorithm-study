int countSubstrings(string s) {
    int n = s.length()-1; // size of isPalindromicCache    
    if(n==0) return 1;    

    vector<vector<bool>> isPalindromicCache(2, vector<bool>(n));
    int ans = n+1; // default answer for every single character of string s
        
    if(s[0] == s[1]){ // case pos = len = 0     
        isPalindromicCache[0][0] = true;    
        ans = ans + 1;     
    }     
    for(int pos=1;pos<n;pos++) // pos+1 index character of the string s        
        for(int len=0;len<pos+1;len++){ // check if substring of s, pos-len to pos+1 character **length of len+2**, is palindromic       
            bool isPalindromic;      
            if(len > 1)        
                isPalindromic = (s[pos+1] == s[pos-len]) && isPalindromicCache[(pos-1)&1][len-2]; // use memorized value       
            else isPalindromic = (s[pos+1] == s[pos-len]);
    
            isPalindromicCache[pos&1][len] = isPalindromic;      
            ans = ans + int(isPalindromic);
        }   
    return ans;    
} // runtime: 20 ms (faster than 46.45 %) , memory usage: 6.4 MB (less than 69.02 %)

/*
- isPalindromicCache: memorize if s[pos-len:pos+2](pos+2 idex is not included) is palindromic string
- for len>1(↔ length of candidate substring > 3) we can define sub-problem for memoization, 
  which is “is s[pos-len:pos+2] palindromic ?” is same as “is s[pos-len] == s[pos+1] ? && is s[pos-len+1:pos+1] is palindromic ?”
- As memoization is used only to adjacent row(adjacent pos, or character of string s), building isPalindromicCache with 2 rows makes no problem.
- Repeating this for all character of string s and all possible length of a substring. During iteration, 
  if the substring with (pos, len) pair is palindromic, count the substring to the answer(# of palindromic substrings).
*/
