int characterReplacement(string s, int k) {
    int len = s.length();
    if(k+1 >= len) return len; // prior knowledge : for all k, length of LRC >= k+1
        
    unordered_map<char, int> charData; // charData : # of char within current window
    int begin = 0, end = k+1; // begin and end of the window
    int num_major_char = 0; // # of major character(target repeating character)
        
    // initialize
    for(int i=begin;i<end;i++)
        charData[s[i]]++;
    for(auto elem: charData)
        num_major_char = max(num_major_char, elem.second);    
    
    // explore
    while(end < len){
        num_major_char = max(num_major_char, ++charData[s[end]]);
           
        if((++end-begin)-num_major_char > k)
            charData[s[begin++]]--;
    }
    return end-begin;
} // runtime : 8 ms (faster than 83.86 %), memory usage : 7 MB (less than 85.08 %)

/*
- prior knowledge : for all k, *the length of the longest repeating characters 
  with replacement operations* is no less than k+1. 
  (pick any substring of length k+1(let s’), and switch k characters to s’[0])
  
- initialization process : For initial window of size k+1, which covers s[0:k+1], 
  make charData hash table and get numbers of major char(target repeating character).
  
- exploration process : 
  extend the size of window(by adding s[end] to the charData) and update num_major_char.
  -> if a substring filtered by a new window meet the rule, iterate exploration process.
  -> if it doesn’t meet the replacement rule, narrow down the size of window
    (by removing the char count of s[begin] from charData and adding 1 to begin)
    
- after the exploration process, end-begin gives us the longest valid size of window, 
  i.e. *the length of the longest repeating characters with replacement operations.*
*/
