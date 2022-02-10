public class Solution
{
    public int[] numslst = new int[10001];
    public int Rob(int[] nums)
    {
        for (int i = 0;i<nums.Length;i++)
        {
            MaxVal(nums, i);
        }
        return numslst[nums.Length - 1];
    }
    public void MaxVal(int[] nums, int idx)
    {
        if (idx == 0) //0개, 1개일 때의 처리
        {
            numslst[0]=nums[0];
        } else if (idx == 1)
        {
            if(nums[0]>nums[1]) {
                numslst[1] = nums[0];
            } else
            {
                numslst[1] = nums[1];
            }
        } else
        {
            if (numslst[idx-2]+nums[idx]>numslst[idx-1])
            {
                numslst[idx] = numslst[idx - 2] + nums[idx];
            }
            else
            {
                numslst[idx] = numslst[idx - 1];
            }
        }
    }
}