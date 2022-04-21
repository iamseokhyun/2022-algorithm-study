/* 1st try(failed)
- checking every group of substring without repeating characters led to fatal runtime inefficiency
- T.C. analysis : 
  while loop - iterate maximum 95 times (# of all printable ASCIIs)
  for loop(pos variable): n - ans , checkCharRepeat: ans-1 
  Total calculation: $\underset{ans = 1}{\overset{95}{\sum}}(\mathrm{n-ans})(\mathrm{ans-1}) = 4465\mathrm{n}-285760$
  if n == 5*10^4, total calculation = 222,964,240 (about 2 sec is needed for test case with time limit exceed)
*/

int lengthOfLongestSubstring(string s) {
    int ans = 0, n = s.length();
    if(n==0) return ans;
    vector<bool> candidate(n-1, true); // as nth char of s is useless
    bool capable = true; // represents if length of ans+1 is possible
      
    while(capable && ++ans<= n){
        capable = false;
        for(int pos=0;pos<n-ans;pos++)
            if(candidate[pos]){
                candidate[pos] = checkCharRepeat(s, pos, ans+1);
                capable = capable||candidate[pos];
            }
    }
    return ans;
}
    
bool checkCharRepeat(string s, int pos, int ans){
    for(int p=pos;p<pos+ans-1;p++)
        if(s[p] == s[pos+ans-1])
            return false;
    return true;
} // check if there is no repeating characters at s<pos:pos+ans>

/* Time Limit Exceed for test case "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO
PQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" X a lot 
(repeating all printable ASCIIs, total 95 codes)*/ 



// 2nd try(succeed)

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if(n <= 1) return n;
        
    int ans = 1, begin = 0, end = 1;
        
    while(end < n){
        if(ans >= 95) break; //95 == # of all printable ASCIIs
        for(int pos = begin; pos < end; pos++)
            if(s[pos] == s[end]){
                begin = pos + 1;
                goto loop_end; // ans is only updated when there is no repeating characters at s[begin:end+1]
            }
        ans = max(ans, end-begin+1);
            
        loop_end: 
        end = end + 1;
    }
    return ans;
} // runtime : 7 ms (faster than 90.79 %), memory usage : 6.9 MB (less than 96.65 %)

/*
- for-loop: check whether there are repeating characters at s[begin:end+1]
¡æ if exist: reset begin(start of the candidate substring)
¡æ if not exist: update ans
- T.C. analysis : O(n) (especially, T ¡Â 94n : for-loop can iterate maximum 94 times)
*/
