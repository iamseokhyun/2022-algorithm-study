// brute-force like search
int hammingWeight(uint32_t n){
    int cnt = 0;				//비트 카운트 변수
    while(n){					//n에 대한 오른쪽 시프트에 의해 n이 0이 될 때까지 반복
    	cnt += n&1;				//맨 오른쪽 자리에 1이 있는경우 카운트 1 추가
        n >>= 1;
    }
    return cnt;
}

// # of 1-bits using bitwise operation (idea from Wikipedia)
uint32_t m1 = 0x55555555;				// binary: 0101 ...
uint32_t m2 = 0x33333333;				// binary: 00110011 ...
uint32_t m4 = 0x0f0f0f0f;				// binary: 4 zeros, 4 ones ...
uint32_t m8 = 0x00ff00ff;				// binary: 8 zeros, 8 ones ...
uint32_t m16 = 0x0000ffff;				// binary: 16 zeros, 16 ones ...

int hammingWeight(uint32_t n) {
    n = (n & m1) + ((n >> 1) & m1);
    n = (n & m2) + ((n >> 2) & m2);
    n = (n & m4) + ((n >> 4) & m4);
    n = (n & m8) + ((n >> 8) & m8);
    n = (n & m16) + ((n >> 16) & m16);
    return n;
}

// a little optimized version
int hammingWeight(uint32_t n) {
    n -= (n >> 1) & m1;				//각 조각에서 10 -> 01로, 01 -> 01로, 11 -> 10으로
    n = (n & m2) + ((n >> 2) & m2);
    n = (n + (n >> 4)) & m4;			// m4에 대한 AND 연산을 한 번에 처리
    n += n >> 8;				// 각 16비트 카운트를 뒷 8비트에 몰아넣기
    n += n >> 16;				// 각 32비트 카운트를 뒷 16비트에 몰아넣기
    return n & 0x3f;				//trash 값을 제거
}

// useful algorithm when most of the bits of binary string are 0
int hammingWeight(uint32_t n) {
    int cnt;
    for(cnt=0; n; cnt++)
    	n &= n-1;			// n의 가장 오른쪽에 있는 1을 0으로 만드는 연산
    return cnt;
}
