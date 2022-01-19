public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        nums = Divide(nums);
        for (int i = 0; i < nums.Length-1; i++)
        {
            if (nums[i+1]-nums[i]==0)
            {
                return true;
            }
        }
        return false;
        
    }
    public int[] Divide(int[] nums)
    {
        if (nums.Length < 2)
        {
            return nums;
        }
        int pivot = (int)(nums.Length / 2);
        int[] leftarray = nums[0..pivot];
        int[] rightarray = nums[pivot..(nums.Length)];
        leftarray = Divide(leftarray);
        rightarray = Divide(rightarray);
        return Merge(leftarray, rightarray);
    }
    public int[] Merge(int[] leftarray, int[] rightarray)
    {
        int l = leftarray.Length - 1;
        int r = rightarray.Length - 1;
        int[] temp = new int[leftarray.Length + rightarray.Length];
        while (l >= 0 && r >= 0)
        {
            if (leftarray[l] > rightarray[r])
            {
                temp[l + r + 1] = leftarray[l];
                l--;
            }
            else
            {
                temp[l + r + 1] = rightarray[r];
                r--;
            }
        }
        while (l >= 0)
        {
            temp[l] = leftarray[l];
            l--;
        }
        while (r >= 0)
        {
            temp[r] = rightarray[r];
            r--;
        }
        return temp;
    }
}
