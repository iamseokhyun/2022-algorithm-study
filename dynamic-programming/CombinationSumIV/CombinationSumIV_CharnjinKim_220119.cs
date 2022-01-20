
public class Solution //Same solution with CoinChange
{
    public int CombinationSum4(int[] nums, int target)
    {
        int[] possibleCount = new int[target + 1];
        for (int i = 1; i < target + 1; i++)
        {
            possibleCount[i] = -1;
        }
        for (int i = 1; i < target + 1; i++)
        {
            possibleCount[i] = Csum(nums, i, ref possibleCount);
        }


        return possibleCount[target];

    }
    public int Csum(int[] nums, int target, ref int[] possibleCount)
    {
        if (possibleCount[target] != -1)
        {
            return possibleCount[target];
        }
        int count = 0;
        foreach (int num in nums)
        {
            if (target - num > 0)
            {
                count += Csum(nums, target - num, ref possibleCount);
            }
            else if (target == num)
            {
                count++;
            }
        }
        return count;
    }
}