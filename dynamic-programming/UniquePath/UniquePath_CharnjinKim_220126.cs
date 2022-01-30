public class Solution {
    public int UniquePaths(int m, int n) {
        long result=1;
        int small = (m>n) ? n : m;
        int big = (m<n) ? n : m;
        for(int i = m+n-2;i>0;i--) { 
            if (i>=big) {
                result*=i;
            } else if (i>=small) {
                continue;
            } else {
                result/=i;
            }
        }
        return (int) result;
    }
}