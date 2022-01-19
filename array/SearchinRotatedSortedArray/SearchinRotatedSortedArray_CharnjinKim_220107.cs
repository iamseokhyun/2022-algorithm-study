public class Solution {
    public int Search(int[] nums, int target) {
        int idx = -1; 
        Find(nums, 0, nums.Length-1, ref idx, target);
        return idx;
    }
    public void Find(int[] nums, int start, int end, ref int ans, int target) {
        if (end-start<2) {
            if (nums[start]==target) {
                ans = start;
            } else if (nums[end]==target) {
                ans = end;
            }
        }
        else {
            int pivot = (int)(end+start)/2;
            if (nums[pivot]<nums[end]) { //case a
                if (nums[pivot+1]<=target && nums[end]>=target) {
                    Sorted(nums, pivot+1, end, ref ans, target);
                } else {
                    Find(nums, start, pivot, ref ans, target); //re
                }
            } else if (nums[pivot]>nums[end]) {//case b
                if (nums[start]<=target && nums[pivot]>=target) {
                    Sorted(nums, start, pivot, ref ans, target);
                } else {
                    Find(nums, pivot+1, end, ref ans, target); //re
                }
            }
        }

    }
    public void Sorted(int[] nums, int start, int end, ref int ans, int target) {
        if (end-start<2) {
            if (nums[start]==target) {
                ans = start;
            } else if (nums[end]==target) {
                ans = end;
            }
        }
        else {
            int pivot = (int) (end+start)/2 ;
            if (nums[pivot]==target) {
                ans = pivot;
            } else if (nums[pivot]>target) {
                Sorted(nums, start, pivot, ref ans, target);
            } else {
                Sorted(nums, pivot+1, end, ref ans, target);
            }
        }

    }
}