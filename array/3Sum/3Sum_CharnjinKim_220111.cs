public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        IList<IList<int>> ans = new List<IList<int>>();
        nums = Divide(nums);
        for (int i = 0;i<nums.Length-2;i++)
        {
            int key = -1 * nums[i];
            if (i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int l = i + 1;
            int r = nums.Length-1;
            while (r>l && l<nums.Length && r>i+1)
            {
                if (l > i + 1 && l < nums.Length && nums[l] == nums[l - 1])
                {
                    l++;
                    continue;
                }
                if (r < nums.Length - 1 && r > i + 1 && nums[r] == nums[r + 1])
                {
                    r--;
                    continue;
                }
                if (nums[l] + nums[r] == key)
                {
                    ans.Add(new int[] { nums[i], nums[l], nums[r] });
                    l++;
                    r--;
                    continue;
                }
                else if (nums[l] + nums[r] > key)
                {
                    r--;
                    continue;
                }
                else
                {
                    l++;
                    continue;
                }

            }

        }
        return ans;
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