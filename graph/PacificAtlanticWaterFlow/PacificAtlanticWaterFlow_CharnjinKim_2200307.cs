using System;
using System.Collections.Generic;
public class Solution {
    public IList<IList<int>> PacificAtlantic(int[][] heights) {
        int r = heights.Length;
        int c = 0;
        if (r > 0)
        {
            c = heights[0].Length;
        }
        int[][] isPacific = isFloodPacific(heights, r, c);
        int[][] isAtlantic = isFloodAtlantic(heights, r, c);
        List<IList<int>> ans = new List<IList<int>>();

        for (int i =0;i<r;i++) {
            for (int j =0;j<c;j++) {
                List<int> pos = new List<int> {i,j};
                if (isPacific[i][j]+isAtlantic[i][j]==2) {
                    ans.Add(pos);
                }
            }
        }
        return ans;
    }
    public int[][] isFloodPacific(int[][] heights, int r, int c) {
        Queue<List<int>> qPos = new Queue<List<int>>();
        int[][] res = new int[r][];
        for (int i = 0; i < r; i++)
        {
            res[i] = new int[c];
        }
        //Dictionary<List<int>, bool> res = new Dictionary<List<int>, bool>() ;
        for (int i =0;i<heights.Length;i++) { //바다와 인접한 부분은 항상 Checked
            res[i][0]=1;
            qPos.Enqueue(new List<int>() {i,0});
        }
        for (int j=0;j<heights[0].Length;j++) {
            res[0][j]=1;
            qPos.Enqueue(new List<int>(){0,j});
        }
        while (qPos.Count!=0) {
            List<int> tmp = qPos.Dequeue();
            int m = tmp[0];
            int n = tmp[1];
            //non res=true, higher than me
            checkUDRL(ref heights, ref res, ref qPos, m,n);
        }
        return res;
    }
    public int[][] isFloodAtlantic(int[][] heights, int r, int c) {
        Queue<List<int>> qPos = new Queue<List<int>>();
        int[][] res = new int[r][];
        for (int i = 0;i<r;i++)
        {
            res[i] = new int[c];
        }
        //Dictionary<List<int>, bool> res = new Dictionary<List<int>, bool>() ;
        for (int i =0;i<heights.Length;i++) { //바다와 인접한 부분은 항상 Checked
            res[i][c-1]=1;
            qPos.Enqueue(new List<int>() {i,c-1});
        }
        for (int j=0;j<heights[0].Length;j++) {
            res[r-1][j]=1;
            qPos.Enqueue(new List<int>(){r-1,j});
        }
        while (qPos.Count!=0) {
            List<int> tmp = qPos.Dequeue();
            int m = tmp[0];
            int n = tmp[1];
            //non res=true, higher than me
            checkUDRL(ref heights, ref res, ref qPos, m,n);
        }
        return res;
    }
    public void checkUDRL(ref int[][]heights, ref int[][] res, ref Queue<List<int>> qPos, int r, int c) {
        //first, check Upperside
        if ((r!=0)&&(res[r-1][c]==0)&&heights[r][c]<=heights[r-1][c]) {
            res[r - 1][c] = 1;
            qPos.Enqueue(new List<int>() {r-1,c});
        }
        if ((r!=heights.Length-1)&&(res[r + 1][c] == 0) &&heights[r][c]<=heights[r+1][c]) { //down
            res[r + 1][c] = 1;
            qPos.Enqueue(new List<int>() {r+1,c});
        }
        if ((c!=heights[0].Length-1)&&(res[r][c+1] == 0) &&heights[r][c]<=heights[r][c+1]) {//Right
            res[r][c+1] = 1;
            qPos.Enqueue(new List<int>() {r,c+1});
        }
        if ((c!=0)&&(res[r][c-1] == 0) &&heights[r][c]<=heights[r][c-1]) {//Left
            res[r][c-1] = 1;
            qPos.Enqueue(new List<int>() {r,c-1});
        }
    }
}