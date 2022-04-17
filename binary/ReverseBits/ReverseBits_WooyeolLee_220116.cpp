uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for(int i=0;i<32;i++){
    	rev = (rev << 1) + (n & 1);		// rev는 1칸 왼쪽으로 밀고, 현재 n의 맨 마지막 자리 수 추가
        n >>= 1;				// n을 1칸 오른쪽으로 밀면서 n이 0이 될 때까지 반복
    }
    return rev;
}

// algorithm like that of Number of 1 Bits
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);	// 8비트씩 값을 추출해서 8비트 시프트
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);	// 4비트씩 값을 추출해서 4비트 시프트
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);	// 2비트씩 값을 추출해서 2비트 시프트
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);	// 1비트씩 값을 추출해서 1비트 시프트
    return n;
}
