public class Solution
{
    public int[] numslst = new int[10001];
    public int[] isUsed1st = new int[3];
    public int Rob(int[] nums)
    {
        if (nums.Length < 4) //trivial solutions
        {
            int max = -1;
            for (int i = 0; i < nums.Length; i++)
            {
                if (max < nums[i])
                {
                    max = nums[i];
                }
            }
            return max;
        }
        else
        {
            for (int i = 0; i < nums.Length; i++)
            {
                MaxVal(nums, i);
            }
            int res = numslst[nums.Length - 1];
            for (int i = 0; i < nums.Length-1; i++)
            {
                MaxVal(nums[1..nums.Length], i);
            }
            if (numslst[nums.Length-2]>res)
            {
                return numslst[nums.Length - 2];
            } else
            {
                return res;
            }
        }
    }
    public void MaxVal(int[] nums, int idx)
    {
        if (idx == 0) //0개, 1개일 때의 처리
        {
            numslst[0] = nums[0];
            isUsed1st[0] = 1;
            return;
        }
        else if (idx == 1)
        {
            if (nums[1]>nums[0])
            {
                numslst[1] = nums[1];
                isUsed1st[1] = -1;
                return;
            }
                else
            {
                numslst[1] = nums[0];
                isUsed1st[1]=1;
                return;
            }

        }
        else if (idx != nums.Length - 1)
        {
            if (numslst[idx - 2] + nums[idx] > numslst[idx - 1])
            {
                numslst[idx] = numslst[idx - 2] + nums[idx];
                isUsed1st[2] = isUsed1st[0];
            }
            else if (numslst[idx - 2] + nums[idx] < numslst[idx - 1])
            {
                numslst[idx] = numslst[idx - 1];
                isUsed1st[2] = isUsed1st[1];
            }
            else
            {
                numslst[idx] = numslst[idx - 1];
                isUsed1st[2] = 0;
            }
        }
        else //마지막 idx
        {
            if (isUsed1st[0] == 1)
            {
                numslst[idx] = (numslst[idx - 2] > numslst[idx - 1]) ? numslst[idx - 2] : numslst[idx - 1];
            }
            else
            {
                numslst[idx] = (numslst[idx - 2] + nums[idx] > numslst[idx - 1]) ? numslst[idx - 2] + nums[idx] : numslst[idx - 1];
            }
        }
        isUsed1st[0] = isUsed1st[1];
        isUsed1st[1] = isUsed1st[2];
    }
}