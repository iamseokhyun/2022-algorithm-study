int cache[300];			// memoization을 위한 배열(s 길의 최댓값 만큼의 크기를 가짐)
std::fill_n(cache, 300, -1);		// 할당된 값이 없음을 의미하는 -1

bool WordBreak(int start, string s, vector<string>& wordDict){		// s[start:]에 대한 WordBreak
    if(start == s.length())
        return true;			// 조건을 만족하는 경우 s에 wordbreak가 완료되었으므로 true
    int& ret=cache[start];
    if(ret != -1)				
        return (bool)ret;		// memoization 값을 bool형태로 출력
        
    ret=0;		// 종료 조건이 line 5밖에 없으므로 이외의 모든 경우를 표현하기 위해 0(false)로 초기화
    for(int wdorder=0;wdorder<wordDict.size();wdorder++){	// wordDict의 모든 원소에 대한 탐색
        bool isMatch = true;
        for(int pos=0;pos<wordDict[wdorder].length();pos++)
            if(s[start+pos] != wordDict[wdorder][pos] || start + wordDict[wdorder].length() > s.length()){
                isMatch = false;
                break;
            }
        if(isMatch)			// s 앞부분부터 wordDict[i]가 포함되어 있다면 
            ret = (int)WordBreak(start+wordDict[wdorder].size(), s, wordDict);		
        if(ret == 1)			// 한번이라도 wordBreak가 성립하면 탐색 종료
            break;
    }
    return (bool)ret;
}

>> run WordBreak(0, s, wordDict)
