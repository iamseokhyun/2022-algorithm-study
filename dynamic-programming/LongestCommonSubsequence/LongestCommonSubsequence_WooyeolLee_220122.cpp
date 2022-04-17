int longestCommonSubsequence(string &a, string &b) {
    vector<vector<short>> DP(a.size()+1, vector<short>(b.size()+1));
    for(int i=0; i<a.size();i++)
        for(int j=0; j<b.size();j++)
            if(a[i] == b[j]) 
                DP[i+1][j+1] = DP[i][j] + 1;
            else 
                DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1]);
    return DP[a.size()][b.size()];
} // TC : O(nm), SC : O(nm)

int longestCommonSubsequence(string &a, string &b){
    if(a.size()<b.size())			// a와 b 중 더 작은 길이의 문자열로 DP의 열 구성
        return longestCommonSubsequence(b,a);
    
    vector<vector<short>> DP(2, vector<short>(b.size()+1));
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            if(a[i]==b[j])
                DP[(i+1)&1][j+1] = DP[i&1][j+1] + 1;
            else
                DP[(i+1)&1][j+1] = max(DP[(i+1)&1][j], DP[i&1][j+1]);
    return DP[a.size()&1][b.size()];
} // TC : O(nm), SC : O(min(n,m))
