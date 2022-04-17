int climbStairs(int n){
    vector<int> cache(n+1);		//메모이제이션을 위해 n+1 크기의 배열 생성
    cache[0] = 1;		//climbStairs(0) = 1로 정의해 계단을 다 올라간 경우를 clear하게 처리
    cache[1] = 1;

    for(int i=2;i<=n;i++)
        data[i] = data[i-1]+data[i-2];		//bottom-up approach
    
    return data[n];
}
