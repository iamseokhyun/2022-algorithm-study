int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;       		//amount가 0인 경우 따로 처리
    vector<int> cache(amount+1);
      
    for(int i=1;i<=amount;i++){      		// 1~amount까지의 부분 문제 memoization
        int ret = 12345;			// amount 최댓값 10^4보다 큰 임의의 값으로 초기화 
        for(int j=0;j<coins.size();j++)
            if(i - coins[j] > 0 && cache[i-coins[j]] != 0){
                ret = min(ret, 1+cache[i-coins[j]]);
                continue;
            }
            else if(i - coins[j] == 0)
                ret  = 1;
        if(ret == 12345) ret = 0;		// 한 번도 조건문을 만족하지 못한 경우 가능한 조합 수 0
        cache[i] = ret;
    }
    if(cache[amount] == 0) return -1;		// 가능한 조합 수가 0 인 경우(amount가 0인 경우와 다른 case)
    else return cache[amount];
}
