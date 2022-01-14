using System;

namespace ReverseBits
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution su = new Solution();
            uint ans = 43261596;
            uint aa = su.reverseBits(ans);
            Console.WriteLine(aa);
        }
    }
    public class Solution
    {
        public uint reverseBits(uint n)
        {
            uint ans = 0;
            int p = 31;
            while (n!=0)
            {
                if (n%2==1)
                {
                    ans = (uint)((uint)ans ^ (int)(1 << p));
                    p--;
                    n>>=1;
                }  else
                {
                    p--;
                    n >>= 1;
                }
            }
            return ans;
        }
    }
}
