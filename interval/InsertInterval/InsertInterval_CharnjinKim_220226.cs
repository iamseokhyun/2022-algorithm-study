using System.Collections.Generic;
using System;
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        List<int[]> intList = new List<int[]>();
        int i = 0;
        for (;i<intervals.Length && intervals[i][1]<newInterval[0];i=i++) {
            intList.Add(intervals[i]);
        }
        int left = newInterval[0];
        int right = newInterval[1];
        for (;i<intervals.Length && intervals[i][1]>=newInterval[0] && intervals[i][0]<=newInterval[1];i++) {
            left = Math.Min(left, intervals[i][0]);
            right = Math.Max(right, intervals[i][1]);
        }
        intList.Add(new int[] {left,right});
        for (;i<intervals.Length;i++) {
            intList.Add(intervals[i]);
        }
        return intList.ToArray();
    }
}