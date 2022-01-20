public class Solution {
    public int HammingWeight(uint n) {
        int i = 0;
        for (int p = 0;p<32;p++) {
            if(Convert.ToBoolean(n%2)) {
            i++;
        } 
        n/=2;    
        }
        return i;

    }
}