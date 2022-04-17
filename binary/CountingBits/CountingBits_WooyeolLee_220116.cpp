vector<int> countBits(int n){
    vector<int> bitcount;
    bitcount.push_back(0);			// 반복문의 편의성을 위해 0에 대한 계산 먼저 처리
    for(int i=1;i<=n;i++){
    	int current_num = i;
    	int cnt = 0;
    	while(current_num){			// 시프트 연산에 의해 current_num이 0이 될 때까지 반복
            cnt+=(current_num%2); 		// 현재 이진표현 상 가장 오른쪽 숫자가 1일경우 카운트
            current_num = (current_num>>1);
        }
        bitcount.push_back(cnt);		// current_num에 해당하는 인덱스에 구한 값(cnt)할당
    }
    return bitcount;
}

vector<int> countBits(int n) {
	vector<int> bitcount;
	bitcount.push_back(0);				//기본 값으로 0에 대한 값 대입
	for(int i=1;i<=n;i++){
            bitcount.push_back(bitcount[i/2] + i & 1);	//2로 나눈 몫, 나머지 고려
	}
	return bitcount;
}
