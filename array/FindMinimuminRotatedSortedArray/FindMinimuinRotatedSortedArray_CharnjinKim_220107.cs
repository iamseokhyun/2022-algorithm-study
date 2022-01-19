public class Solution {
    public int FindMin(int[] nums) {
        int idx = 0;
        Find(nums, 0, nums.Length-1, ref idx);
        Console.WriteLine(idx);
        return nums[idx];
    }
    public void Find(int[] nums, int strt, int end, ref int ans) {
        if (end ==strt) {
            ans = strt;
        } else {
            int pivot = (int) ((end-strt)/2);
            pivot+=strt;
            if (nums[pivot]<nums[end]) {
                Find(nums, strt, pivot, ref ans);
            } else {
                Find(nums, pivot+1, end, ref ans);
            }
        }
    }
}