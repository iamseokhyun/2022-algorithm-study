using System.Collections.Generic;
using System;
using System.Linq;
public class Solution {
    public int[][] Merge(int[][] intervals) {
        if (intervals.Length==1) {
            return intervals;
        }
        List<int[]> intList = new List<int[]>();
        for (int i = 0;i<intervals.Length;i++) {
            intList.Add(intervals[i]);
        }
        List<int[]> sintList = intList.OrderBy(x=>x[0]).ToList();
        List<int[]> res = new List<int[]>();
        int first=sintList[0][0];
        int last=sintList[0][1];
        for (int i =1;i<intervals.Length;i++) {
            if (sintList[i][0]<=last) {
                last = Math.Max(sintList[i][1], last);
            } else {
                res.Add(new int[] {first, last});
                first = sintList[i][0];
                last = Math.Max(sintList[i][1], last);
            }
            if (i==intervals.Length-1) {
                res.Add(new int[] {first, last});
            }
        }
        return res.ToArray();

    }
}