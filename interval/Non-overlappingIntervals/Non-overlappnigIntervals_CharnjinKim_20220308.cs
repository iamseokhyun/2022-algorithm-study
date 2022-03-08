using System;
using System.Linq;

    public class Solution {
        public int EraseOverlapIntervals(int[][] itv) {
            if (itv.Length ==0) {
                return 0;
            }
            itv = itv.OrderBy(x=>x[0]).OrderBy(x=>x[1]).ToArray();
            int lastidx = itv[0][1];
            int cnt =1;
            foreach (int[] item in itv) {
                if (item[0]>=lastidx) {
                    cnt++; 
                    lastidx = item[1];
                }
            }
            return itv.Length-cnt;
        }
    }