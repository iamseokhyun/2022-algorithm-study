#include <sstream>
using namespace std;

int numDecodings(string s) {
    vector<int>cache(2);
               
    if(s[0] == '0') return 0;  // 첫 원소로 0이 나오면 반드시 불가능하므로 0 리턴
    cache[0] = 1;
    if(s[0] != '0')
        cache[1] = 1;
      
    for(int i=1;i<s.size();i++){
        int temp;
        stringstream ssInt(s.substr(i-1,2));  // leetcode에서 stoi를 지원하지 않아 sstream 사용
        ssInt >> temp;
        
        if(temp < 10 || temp > 26)
            cache[(i+1)&1] = 0;
        if(s[i] != '0')
            cache[(i+1)&1] += cache[i&1];
    }
    return cache[s.size()&1];
}
