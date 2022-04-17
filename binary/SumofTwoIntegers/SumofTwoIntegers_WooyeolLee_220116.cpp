int getSum(int a, int b) {
    int carry = a & b;
    int sum = a ^ b;
    while(carry){				// carry가 없을 때까지 실행
        int temp = carry <<1;
        carry = temp & sum;
        sum ^= temp;
    }
    return sum;
}
//Line 6: Char 34: runtime error: left shift of negative value -2147483648 (solution.cpp) SUMMARY: 
//UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:15:34

// as << is not well-defined in cpp

int getSum(int a, int b) {
    int carry = a & b;
    int sum = a ^ b;
    while(carry)
    {
        int temp = (carry & 0xffffffff) <<1; 	//not a problem anymore!
        carry = temp & sum;
        sum ^= temp;
    }
    return sum;
}
