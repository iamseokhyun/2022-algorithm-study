public class Solution
{
    public int GetSum(int e, int d)
    {
        int c=0;
        uint ans = 0;
        int i = 1;
        uint a = (uint)e;
        uint b = (uint)d;
        bool first = true;
        if(a==0)
        {
            return (int)b;
        } else if (b==0)
        {
            return (int)a;
        }
        while (a != 0 || b != 0)
        {
            if (c==0)
            {
                if (Convert.ToBoolean((a % 2) & (b % 2)))
                {
                    c = 1;
                } else
                {
                    c = 0;
                }
                if (first)
                {
                    ans = ans | ((a % 2) ^ (b % 2));
                    first = false;
                    i = i << 1;

                }
                else
                {
                    ans = (uint)(ans | ((a % 2) ^ (b % 2)) * i);
                    i = i << 1;
                }
            }
            else
            {
                ans = (uint)(ans | ((a % 2) ^ (b % 2) ^ c) * i);
                i = i << 1;
                if (Convert.ToBoolean(((a % 2) & (b % 2))|((c) & (b % 2))|((a % 2) & (c))))
                {
                    c = 1;
                } else
                {
                    c = 0;
                }
            }
            a = a >> 1;
            b = b >> 1;
        }
        if (c==1)
        {
            ans = (uint)(ans | i);
        }
        return (int) ans;
    }
}