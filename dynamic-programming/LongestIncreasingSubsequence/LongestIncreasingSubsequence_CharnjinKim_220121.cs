using System;
using System.Collections.Generic;
using System.Linq;

public class Solution { 
    public int LengthOfLIS(int[] nums) {
        List<int> numsList = nums.ToList();
        var sorted = numsList
            .Select((x, i) => new KeyValuePair<int, int>(x, i))
            .OrderByDescending(x => x.Key)
            .ToList();
        List<int> idx = sorted.Select(x => x.Value).ToList();
        int i =0;
        int[] numsidx = new int[nums.Length];
        foreach (int item in idx) {
            numsidx[item]=i;
            i++;
        }
        int[] numsRank = new int[nums.Length];
        for (int j =0;j<nums.Length;j++) {
            int p = numsidx[j];
            int max = 0;
            for (int k=p+1;k<nums.Length;k++) {
                if (max<numsRank[k]) {
                    max = numsRank[k];
                }
            }
            numsRank[p]=max+1;
        }
        int maxv = 0;
        for (int o =0;o<nums.Length;o++) {
            if(maxv<numsRank[o]) {
                maxv = numsRank[o];
            }
        }
        return maxv;
    }

}