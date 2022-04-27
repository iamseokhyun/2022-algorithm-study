string longestPalindrome(string s) {
    int n = s.length()-1; // size of isPalindromicCache
    vector<vector<bool>> isPalindromicCache;     
    for(int i=0;i<n;i++)
        isPalindromicCache.push_back(vector<bool>(i+1, false));
             
    // default longest palindromic substring : s[0] -> length = 1
    int max_len = 1, max_len_pos = 0;        
    if(s[0] == s[1]){ // case pos = len = 0
        isPalindromicCache[0][0] = true;
        max_len = 2; max_len_pos = 1;     
    }         
    for(int pos=1;pos<n;pos++) // pos+1 index character of the string s        
        for(int len=0;len<pos+1;len++){ // check if substring of s, pos-len to pos+1 character **length of len+2**, is palindromic       
            bool isPalindromic = (s[pos+1] == s[pos-len]);               
            if(isPalindromic && len > 1)                  
                isPalindromic = isPalindromicCache[pos-1][len-2]; // use memorized value                               

            if(isPalindromic){                
                isPalindromicCache[pos][len] = true;         
                if(max_len < len + 2){                        
                    max_len = len + 2;            
                    max_len_pos = pos + 1;        
                }       
            }    
        }        
    return s.substr(max_len_pos-max_len+1, max_len);       
} // runtime : 235 ms (faster than 45.08 %), memory usage : 28.6 MB (less than 39.33 %)

/*
- isPalindromicCache: memorize if s[pos-len:pos+2](pos+2 idex is not included) is palindromic string
- for len>1(↔ length of candidate substring > 3) we can define sub-problem for memoization, 
  which is “is s[pos-len:pos+2] palindromic ?” is same as “is s[pos-len] == s[pos+1] ? && is s[pos-len+1:pos+1] is palindromic ?”
- Repeating this for all character of string s and all possible length of a substring.
- During this iteration, update longest length of palindromic substring and its last index.
*/



string longestPalindrome(string s) {    
    int n = s.length()-1; // size of isPalindromicCache    
    vector<vector<bool>> isPalindromicCache(2,vector<bool>(n));    
   
    // default longest palindromic substring : s[0] -> length = 1
    int max_len = 1, max_len_pos = 0;         
    if(s[0] == s[1]){ // case pos = len = 0   
        isPalindromicCache[0][0] = true;    
        max_len = 2; max_len_pos = 1;    
    }        
    for(int pos=1;pos<n;pos++) // pos+1 index character of the string s        
        for(int len=0;len<pos+1;len++){ // check if substring of s, pos-len to pos+1 character **length of len+2**, is palindromic       
            bool isPalindromic = (s[pos+1] == s[pos-len]);                
            if(isPalindromic && len > 1)                   
                isPalindromic = isPalindromicCache[(pos-1)&1][len-2]; // use memorized value                               
        
            if(isPalindromic){                    
                isPalindromicCache[pos&1][len] = true;                 
                if(max_len < len + 2){                                  
                    max_len = len + 2;              
                    max_len_pos = pos + 1;         
                }        
            }
            else isPalindromicCache[pos&1][len] = false;
        }          
    return s.substr(max_len_pos-max_len+1, max_len);
} // remarkable memory usage decrease (28.6 MB -> 7.4 MB)

/*
- As memoization is used only to adjacent row(adjacent pos, or character of string s), 
  building isPalindromicCache with 2 rows makes no problem.
- Through submission details, I can find it shows remarkable memory usage decrease 
  (28.6 MB : isPalindromicCache with n**2/2 bit cells → 7.4 MB : isPalindromicCache with 2n bit cells).
*/
