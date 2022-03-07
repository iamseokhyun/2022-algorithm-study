using System;
using System.Collections.Generic;


public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int p1 = 0;
        int p2 = 1;
        int max = 0;
        List<char> strDict = new List<char>();
        strDict.Add(s[p1]);
        while (p2<s.Length) {
            if (p1==p2) {
                p2++;
                strDict.Add(s[p1]);
                continue;
            } else if (strDict.Contains(s[p2])) {
                max = (max>(p2-p1)) ? max : (p2-p1);
                p1++;
                strDict = new List<char>();
                for (int i =p1;i<p2;i++)
                {
                    strDict.Add(s[i]);
                }
            } else {
                strDict.Add(s[p2]);
                p2++;
            }
        }
        return max;
    }
}