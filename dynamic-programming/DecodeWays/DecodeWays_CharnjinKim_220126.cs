using System;
public class Solution {

    public int NumDecodings(string s) {
        int[] nums = new int[s.Length];
        int ways = 1;
        for (int i =0;i<s.Length;i++) {
            nums[i]=s[i]-48;
        }
        bool onetwoMode = false;
        int[] onetwoNums = new int[0];
        for (int i = 0;i<s.Length;i++) {
            if (!onetwoMode && (nums[i]==1||nums[i]==2)) {
                onetwoMode=true;
                onetwoNums = new int[1] {nums[i]};
            }
            else if (onetwoMode && i == s.Length - 1)
            {
                Array.Resize<int>(ref onetwoNums, onetwoNums.Length + 1);
                onetwoNums[onetwoNums.Length - 1] = nums[i];
                ways *= oneTwoVal(onetwoNums);
                onetwoMode = false;
            }
            else if (onetwoMode && (nums[i]==1||nums[i]==2)) {
                Array.Resize<int>(ref onetwoNums, onetwoNums.Length+1);
                onetwoNums[onetwoNums.Length-1] = nums[i];
            } else if (onetwoMode) {
                Array.Resize<int>(ref onetwoNums, onetwoNums.Length + 1);
                onetwoNums[onetwoNums.Length - 1] = nums[i];
                ways *=oneTwoVal(onetwoNums);
                onetwoMode=false;
            }
            else if (nums[i]==0) {
                return 0;
            }
        }
        return ways;
    }
    public int oneTwoVal(int[] nums) {
        if (nums[nums.Length - 1] == 0) {
            return ClimbStairs(nums.Length - 1);
        } else if (nums[nums.Length - 2] == 2 && nums[nums.Length - 1] > 6) {
            return ClimbStairs(nums.Length - 1);
        } else
        {
            return ClimbStairs(nums.Length);
        }
    }
    public int ClimbStairs(int n) {
        int[] fib = new int[n+1]; 
        for (int i = 1; i<n+1;i++) {
            if (i<=2) {
                fib[i] = i;
            } else {
                fib[i] = fib[i-1]+fib[i-2];
            }
        }
        return fib[n];
    }
}