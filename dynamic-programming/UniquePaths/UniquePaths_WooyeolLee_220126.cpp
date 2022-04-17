int uniquePaths(int m, int n) {
    if(m < n)
        return uniquePaths(n, m); // 메모리 사용을 최소화 하기 위함
    
    vector<vector<int>> cache(2,vector<int>(n));
    for(int i=0;i<n;i++)   // 1행과 1열의 값은 1로 정해져 있으므로 먼저 초기화
        cache[0][i] = 1;
    cache[1][0] = 1;
    
    for(int i=1;i<m;i++)  // 최초 초기화한 1행, 1열을 제외한 나머지 부분 할당
        for(int j=1;j<n;j++) 
            cache[i&1][j] = cache[i&1][j-1] + cache[(i-1)&1][j];
     
    return cache[(m-1)&1][n-1];
}


int uniquePaths(int m, int n) {
    // ans: m+n-2 C n-1
    if(m < n)
        return uniquePaths(n, m);
        
    long ans = 1;
    for(int i=1;i<n;i++)
        ans = ans* (m-1+i) / i;
    
    return (int)ans;
}
