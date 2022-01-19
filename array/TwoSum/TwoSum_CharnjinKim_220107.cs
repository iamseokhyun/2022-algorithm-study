public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        int index = -1, idx1=-1, idx2=-1;
        int[] copy = nums;
        nums = Divide(nums);
        for (int k = 0; k < nums.Length; k++)
        {
            index = -1;
            BinarySearch(nums, target - nums[k], 0, ref index);
            if (index == -1)
            {
                continue;
            }
            if (nums[index]*2==target)
            {

                    return SearchMultipleIndex(copy, nums[index]);
            }
            else
            {
                idx1 = k;
                break;
            }

        }
        idx2=SearchIndex(copy, nums[index]);
        int idx3 = SearchIndex(copy, nums[idx1]);
        return new int[] { idx3, idx2 };

    }
    public void BinarySearch(int[] nums, int target, int indexnow, ref int index)
    {
        if (nums.Length<2)
        {
            if (nums[0] == target)
            {
                index = indexnow;
            }
            else
            {
                return;
            }
        }
        int pivot = (int)(nums.Length / 2);
        if (nums[pivot]>target)
        {
            BinarySearch(nums[0..pivot], target, indexnow, ref index);
        }
        else if (nums[pivot]<target)
        {
            BinarySearch(nums[pivot..(nums.Length)], target, indexnow + pivot, ref index);
        }
        else
        {
            index = indexnow+pivot;
        }
    }
    public int SearchIndex(int[] nums, int target)
    {
        for (int i = 0; i<nums.Length;i++)
        {
            if (nums[i]==target)
            {
                return i;
            }

        }
        return 0; //not searched
    }
    public int[] SearchMultipleIndex(int[] nums, int target)
    {
        int itmp1 = -1;
        bool foundfirstone = false;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == target && foundfirstone==false)
            {
                itmp1=i;
                foundfirstone = true;
                continue;
            }
            else if (nums[i]==target && foundfirstone==true)
            {
                return new int[] { itmp1, i };
            }

        }
        return new int[] { 0}; //not searched
    }
    public int[] Divide(int[] nums)
    {
        if (nums.Length < 2)
        {
            return nums ;
        }
        int pivot = (int)(nums.Length / 2);
        int[] leftarray = nums[0..pivot];
        int[] rightarray = nums[pivot..(nums.Length)];
        leftarray=Divide(leftarray);
        rightarray=Divide(rightarray);
        return Merge(leftarray, rightarray);
    }
    public int[] Merge(int[] leftarray, int[] rightarray)
    {
        int l = leftarray.Length-1;
        int r = rightarray.Length-1;
        int[] temp = new int[leftarray.Length + rightarray.Length];
        while (l>=0 && r>=0)
        {
            if (leftarray[l]>rightarray[r])
            {
                temp[l + r+1] = leftarray[l];
                l--;
            }
            else
            {
                temp[l + r+1] = rightarray[r];
                r--;
            }
        }
        while (l>=0)
        {
            temp[l] = leftarray[l];
            l--;
        }
        while (r>=0)
        {
            temp[r] = rightarray[r];
            r--;
        }
        return temp;
    }
}