using System;
public class Solution {

    public bool CanJump(int[] nums) {
        bool[] isChecked = new bool[nums.Length];
        return CanJump(nums,0, ref isChecked);
    }
    public bool CanJump(int[] nums, int pointer, ref bool[] isChecked) {
        if (nums[pointer]+pointer>=nums.Length-1) {
            return true;
        }
        for(int i = nums[pointer];i>0 && !isChecked[pointer+i];i--) {
            if (CanJump(nums, pointer+i, ref isChecked)){
                return true;
            }
        }
        isChecked[pointer]= true;
        return false;
    }
}