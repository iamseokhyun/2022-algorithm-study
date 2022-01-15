public class Solution
{
    public int MaxProfit(int[] prices)
    {
        int res = 0;
        int min = 99999;
        for (int i = 0;i<prices.Length;i++)
        {
            if (prices[i]<min)
            {
                min = prices[i];
            }
            else if (res < prices[i] - min)
            {
                res = prices[i] - min;
            }
        }
        return res;
    }

}
