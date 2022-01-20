public class Solution {
    public int ClimbStairs(int n) {
        int[] fib = new int[n+1]; //ith index에 fibonacci[i]이 들어가도록. 
        for (int i = 1; i<n+1;i++) {
            if (i<=2) {
                fib[i] = i; //fib[1]=1, fib[2]=2
            } else {
                fib[i] = fib[i-1]+fib[i-2];
            }
        }
        return fib[n];
    }
}