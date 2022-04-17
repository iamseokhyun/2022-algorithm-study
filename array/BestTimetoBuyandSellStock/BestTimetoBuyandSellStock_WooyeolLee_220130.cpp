int maxProfit(vector<int>& prices) {
    int low = prices[0];
    int high = 0;
    int profit = 0;
    
    for(int i=1;i<prices.size(); i++){
        if(low > prices[i]){			// 최솟값 재설정 시 최댓값 리셋
            low = prices[i];
            high = 0;
        }
        high = max(high, prices[i]);
        profit = max(profit, high - low);
    }
    return profit;
}
