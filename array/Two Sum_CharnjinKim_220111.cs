﻿using System;
using System.Collections.Generic;

namespace Two_sum
{
    class Program 
    {
        static void Main(string[] args)
        {
            Solution su = new Solution();
            int[] nums = new int[] {2, 5, 5, 11};
            int[] ans = su.TwoSum(nums, 10);
            Console.WriteLine(ans[0]);
            Console.WriteLine(ans[1]);
        }
    }
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> array = new Dictionary<int, int>();
            for (int i = 0; i<nums.Length;i++)
            {
                int key = target - nums[i];
                if (array.ContainsKey(key))
                {
                    return new int[] { array[key], i };
                }
                else if (!array.ContainsKey(nums[i]))
                {
                    array.Add(nums[i], i);
                }
            }
            return new int[] { 0 }; // for non-error
        }
    }
}
