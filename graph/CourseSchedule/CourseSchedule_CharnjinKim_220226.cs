using System.Collections.Generic;
using System;
public class Solution {
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        Dictionary<int, List<int>> prer = new Dictionary<int, List<int>>();
        Dictionary<int, List<int>> numsList = new Dictionary<int, List<int>>();
        for (int i =0;i<numCourses;i++) {
            prer[i]= new List<int>();
        }
        foreach (var item in prerequisites) {
            prer[item[0]].Add(item[1]); //prer[i] : List<int>, i를 듣기 위해선 prer[i]의 원소들을 다 들어야 함.
            if (!numsList.ContainsKey(item[1])) {
                numsList.Add(item[1], new List<int> {item[0]});
            } else {
            numsList[item[1]].Add(item[0]); //i -> numsList[i], i를 들어야 numsList[i]를 들을 수 있음.
            }
        }
        while (prer.Count>0) { // Must add constraients
            int[] noList = Find(ref prer);
            if (noList[0]==-1) {
                return false;
            }
            for (int i =0;i<noList.Length;i++) {
                int cur = noList[i];
                if (numsList.ContainsKey(cur)) {
                    foreach (int item in numsList[cur]) {//Visit toRemove 의 원소, and remove vals from prer
                        prer[item].Remove(cur);
                    }
                }
            }
        }
        return true;
    }
    public int[] Find(ref Dictionary<int, List<int>> prer) {
        int[] findList = new int[0];
        foreach (int item in prer.Keys)
        {
            if (prer[item].Count==0)
            {
                Array.Resize<int>(ref findList, findList.Length + 1);
                findList[findList.Length - 1] = item;
                prer.Remove(item);
            }
        }
        if (findList.Length==0) {
            return new int[] {-1};
        }
        return findList;
    }
}