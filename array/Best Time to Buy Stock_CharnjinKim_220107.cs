using System;
using System.Collections;

namespace BestTimeToBuyStock
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution su = new Solution();
            int[] prices = new int[] { 5, 6, 7, 3, 4, 5 };
            int a = su.MaxProfit(prices);
            Console.WriteLine(a);
        }
    }
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
}
