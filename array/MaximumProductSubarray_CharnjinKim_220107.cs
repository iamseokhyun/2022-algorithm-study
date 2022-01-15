public class Solution
{
    public int MaxProduct(int[] nums)
    {
        int istrt = 0;
        int tmp = 0;
        bool isStarted = false;
        int max = nums[0];
        bool isZero = false;
        for (int i = 0;i<nums.Length;i++)
        {
            if (nums[i]==0)
            {
                isZero = true;
                if (isStarted)
                {
                    tmp= NoZeroMax(nums[istrt..i]);
                    if (tmp>max)
                    {
                        max = tmp;
                    }
                    isStarted = false;
                }
            } else
            {
                if (!isStarted)
                {
                    isStarted = true;
                    istrt = i;
                }
            }
        }
        if (isStarted)
        {
            tmp  = NoZeroMax(nums[istrt..nums.Length]);
            if (tmp>max)
            {
                max = tmp;
            }
        }
        if (isZero)
        {
            if (max<0)
            {
                return 0;
            }
        }
        return max;
    }
    public int NoZeroMax(int[] nums)
    {
        if (nums.Length==1)
        {
            return nums[0];
        } else
        {
            int minuscnt = 0;
            int idx1 = -1;
            int idx2 = -1;
            for (int i = 0;i<nums.Length;i++)
            {
                if (nums[i]<0)
                {
                    if (idx1==-1)
                    {
                        idx1 = i;
                    }
                    minuscnt++;
                    idx2 = i;
                }
            }
            if ((minuscnt%2)==0)
            {
                int prod = 1;
                for (int i =0;i<nums.Length;i++)
                {
                    prod *= nums[i];
                }
                return prod;
            } else
            {
                int prod = 1;
                for (int i = 0; i < nums.Length; i++)
                {
                    prod *= nums[i];
                }
                int byprod1 = 1;
                for (int i = 0;i<=idx1;i++)
                {
                    byprod1 *= nums[i];
                }
                int byprod2 = 1;
                for (int i =idx2;i<nums.Length;i++)
                {
                    byprod2 *= nums[i];
                }
                if (byprod1>byprod2)
                {
                    return prod / byprod1;
                } else
                {
                    return prod / byprod2;
                }
            }
        }
    }
}