public class Solution
{
    public int[] CountBits(int n)
    {
        int[] save = new int[n+1];
        int last2 = 1;
        for (int i = 1; i <= n; i++)
        {

            if (i == last2)
            {
                save[i] = 1;
                last2=last2 << 1;
                continue;
            } else
            {
                save[i] = save[last2>>1] + save[i - (last2>>1)];
            }
        }
        return save;
    }
}