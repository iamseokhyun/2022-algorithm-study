// algorithm ver-1
#include <unordered_map>

struct charInfo{    
    int num_char_t = 0;       
    int num_char_subs = 0;    
};    
string minWindow(string s, string t) {        
    int m = s.length(), n = t.length();    
    if(m < n) return "";           
    
    // save char data of string t
    unordered_map<char, charInfo> Dict;     
    for(char c : t) Dict[c].num_char_t++;          
		
    // before using sliding window, initialize beginning and end of the window
    int begin = 0;    
    while(begin != m && !Dict.count(s[begin])) begin++;    
    int end = begin, cnt = n; // cnt : # of characters not included in the window    

    int min_begin = begin, min_len = m + 1; // informations of minimum window substring    

    // sliding window process
    for(;end != m; end++)        
        if(Dict.count(s[end])){                  
            if(Dict[s[end]].num_char_t >= ++Dict[s[end]].num_char_subs) // add s[end] to the window(++Dict[s[end]].num_char_subs) 
                cnt--; // if # of characters at window is less than # of characters at string t, decrement cnt by 1
            else           
                if(s[begin] == s[end]){ // if window contains all the characters at t and s[begin] == s[end](-> can update beginning of the window)
                    Dict[s[begin++]].num_char_subs--;       
                    while(!Dict.count(s[begin]) || Dict[s[begin]].num_char_t < Dict[s[begin]].num_char_subs){     
                        if(Dict.count(s[begin])) Dict[s[begin]].num_char_subs--;     
                        begin++;         
                    } // increment stops when s[begin] is in the string t and # of s[begin] at window is equal to # of s[begin] at string t
                } 
                       
            if(cnt) continue; // if window doesn't contain all the characters at t, skip minimum window update
            if(min_len > end - begin + 1){    
                min_len = end - begin + 1;   
                min_begin = begin;  
            }    
        }           
    
    if(min_len == m+1) return ""; // if there is no valid window, return empty string
    return s.substr(min_begin, min_len);    
} // runtime : 27 ms (faster than 50.86 %), memory usage : 7.6 MB (less than 82.30 %)

/*
- idea : 
1) Make a dictionary that contains characters of string t and the number of the character.
2) Initialize sequence of <character, index> until finding all characters of string t from string s.
3) Exploring remaining characters of string s. When there is any character which is in a dictionary, remove the headmost character from the sequence and insert the current character and its index. Then, update minimum length of window and its start index.
- Time complexity analysis:
  make Dictionary : O(m)
  initializing charPos & exploring string s: O(mn)
  → total T.C. is O(mn) (not a great performance)
*/



// algorithm ver-2
#include <unordered_map>

struct charInfo{    
    int num_char_t = 0;       
    int num_char_subs = 0;    
};    
string minWindow(string s, string t) {        
    int m = s.length(), n = t.length();    
    if(m < n) return "";           
    
    // save char data of string t
    unordered_map<char, charInfo> Dict;     
    for(char c : t) Dict[c].num_char_t++;          
		
    // before using sliding window, initialize beginning and end of the window
    int begin = 0;    
    while(begin != m && !Dict.count(s[begin])) begin++;    
    int end = begin, cnt = n; // cnt : # of characters not included in the window    

    int min_begin = begin, min_len = m + 1; // informations of minimum window substring    

    // sliding window process
    for(;end != m; end++)        
        if(Dict.count(s[end])){                  
            if(Dict[s[end]].num_char_t >= ++Dict[s[end]].num_char_subs) // add s[end] to the window(++Dict[s[end]].num_char_subs) 
                cnt--; // if # of characters at window is less than # of characters at string t, decrement cnt by 1
            else           
                if(s[begin] == s[end]){ // if window contains all the characters at t and s[begin] == s[end](-> can update beginning of the window)
                    Dict[s[begin++]].num_char_subs--;       
                    while(!Dict.count(s[begin]) || Dict[s[begin]].num_char_t < Dict[s[begin]].num_char_subs){     
                        if(Dict.count(s[begin])) Dict[s[begin]].num_char_subs--;     
                        begin++;         
                    } // increment stops when s[begin] is in the string t and # of s[begin] at window is equal to # of s[begin] at string t
                } 
                       
            if(cnt) continue; // if window doesn't contain all the characters at t, skip minimum window update
            if(min_len > end - begin + 1){    
                min_len = end - begin + 1;   
                min_begin = begin;  
            }    
        }           
    
    if(min_len == m+1) return ""; // if there is no valid window, return empty string
    return s.substr(min_begin, min_len);    
} // runtime : 27 ms (faster than 50.86 %), memory usage : 7.6 MB (less than 82.30 %)

/*
- Dict<char, charInfo> save the number of char at string t and at current window(num_char_t, num_char_subs)
- window always start with a character which is in string t.
- Time Complexity : save char data for string t - O(n) + sliding window - O(m) = O(m+n)
- Extra Space Complexity : Dict - O(n)
*/



// algorithm ver-3
#include <unordered_map>

string minWindow(string s, string t) {
    int m = s.length(), n = t.length();
    if(m < n) return "";
    
    // save char data of string t   
    unordered_map<char, int> Dict;
    for(char c : t) Dict[c]++;
        
    // before using sliding window, initialize beginning and end of the window
    int begin = 0;    
    while(begin != m && !Dict.count(s[begin])) begin++;    
    int end = begin, cnt = n; // cnt : # of characters not included in the window
        
    int min_begin = begin, min_len = m + 1; // informations of minimum window substring
    
    // sliding window process
    for(;end != m; end++)
        if(Dict.count(s[end])){
            if(Dict[s[end]]-- > 0) cnt--; // if # of characters at window is less than # of characters at string t, decrement cnt by 1
            else 
                while(!Dict.count(s[begin]) || Dict[s[begin]] < 0){
                    if(Dict.count(s[begin])) Dict[s[begin]]++;
                    begin++;
                } // increment stops when s[begin] is in the string t and # of s[begin] at window is equal to # of s[begin] at string t
                    
            if(cnt) continue; // if window doesn't contain all the characters at t, skip minimum window update
            if(min_len > end - begin + 1){
                min_len = end - begin + 1;
                min_begin = begin;
            }
        }
        
    if(min_len == m+1) return ""; // if there is no valid window, return empty string
    return s.substr(min_begin, min_len);
} // runtime 25 ms (faster than 54.46 %), memory usage : 7.7 MB (less than 82.30 %)

/*
- merge charInfo into one int 
→ if int > 0: there is missing character at window, 
       int == 0: # characters at window is equal to # characters at string t, 
       int < 0: window has more characters than at string t
- simplify the update of the beginning of the window
*/
