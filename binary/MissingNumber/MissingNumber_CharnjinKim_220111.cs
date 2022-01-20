public class Solution {
    public int MissingNumber(int[] nums) {
        int a = nums.Length *(nums.Length+1) / 2;
        int tot=0;
        for (int i = 0;i<nums.Length;i++) {
            tot+=nums[i];
        }
        return a-tot;
    }
}