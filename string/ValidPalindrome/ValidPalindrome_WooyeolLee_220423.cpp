/* 1st algorithm
- 1st block of the code is pre-processing to make string s has only alphanumeric characters.
- 2nd block of the code is checking string s is a palindrome.
- As this algorithm need additional space for string alphnum, I came up with another algorithm that using string::erase for pre-processing.
*/
#include <algorithm>

bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string alphnum;
    for(char c : s){
        if(c >= 'a' && c <= 'z')
            alphnum.push_back(c);
        else if(c >= '0' && c <= '9')
            alphnum.push_back(c);
    }
        
    int front = 0, back = alphnum.length()-1;
    while(front < back)
        if(alphnum[front++] != alphnum[back--])
            return false;
    return true;
} // runtime : 9 ms, memory usage : 7.6 MB



/* 2nd algorithm
- Though there is no need for additional memory usage, the algorithm shows poor runtime performance. 
  I assume that it’s because string::erase operation needs to shift all characters after the position of the character(or characters) erased. 
  This process takes a lot of time if string s has many non-alphanumeric characters, which is inefficient.
*/
#include <algorithm>

bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
        
    string::iterator iter = s.begin();
    while(iter != s.end()){
        if(*iter >= 'a' && *iter <= 'z')
            iter++;
        else if(*iter >= '0' && *iter <='9')
            iter++;
        else s.erase(iter);
    }
      
    int front = 0, back = s.length()-1;
    while(front < back)
        if(s[front++] != s[back--])
            return false;
    return true;
} // runtime : 535 ms, memory usage : 7.4 MB
