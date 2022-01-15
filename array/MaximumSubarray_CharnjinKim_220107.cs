public class Solution
{
    public int MaxSubArray(int[] nums)
    {
        if (nums.Length == 1)
        {
            return nums[0];
        }
        int[] subtotal = new int[nums.Length];
        int tmp = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            tmp += nums[i];
            subtotal[i] = tmp;
        }
        int res = int.MinValue;
        int min = int.MaxValue;
        bool up = false;
        for (int i = 0; i < subtotal.Length; i++)
        {
            if (subtotal[i] < min)
            {
                min = subtotal[i];
            }
            else if (res < subtotal[i] - min)
            {
                up = true;
            }
            res = subtotal[i] - min;
        }
        if (up == false)
        {
            int small = int.MinValue;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > small)
                {
                    small = nums[i];
                }
            }
            return small;
        }
        return res;
    }
}