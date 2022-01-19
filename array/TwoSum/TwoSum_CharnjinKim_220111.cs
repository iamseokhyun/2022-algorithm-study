public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> array = new Dictionary<int, int>();
        for (int i = 0; i<nums.Length;i++)
        {
            int key = target - nums[i];
            if (array.ContainsKey(key))
            {
                return new int[] { array[key], i };
            }
            else if (!array.ContainsKey(nums[i]))
            {
                array.Add(nums[i], i);
            }
        }
        return new int[] { 0 }; // for non-error
    }
}