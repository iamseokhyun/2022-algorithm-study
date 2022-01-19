public class Solution
{
    public int[] ProductExceptSelf(int[] nums)
    {
        int l = nums.Length;
        int[] output = new int[l];
        output[0] = 1;

        for (int i = 1; i < l; i++)
        {
            output[i] = output[i-1] * nums[i-1];
        }
        int r = 1;
        output[l - 1] *= nums[l - 1];
        for (int i = l - 1; i > -1; i--)
        {
            output[i] *= r;
            r *= nums[i];

        }
        return output;
    }
    static void Main(String[] args)
    {
        Solution su = new Solution();
        int[] a = new int[] { 1, 2, 3, 4 };
        int[] b = su.ProductExceptSelf(a);
        foreach(int item in b)
        {
            Console.WriteLine(item);
        }
    }
}