using System.Collections.Generic;

public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int r = matrix.Length;
        int c = 0;
        if (r>0) {
            c = matrix[0].Length;
        }
        int ri=0, ci=0;
        List<int> res = new List<int>();
        for (int i =0;r!=0 && c!=0;i++) {
            if (i==0) {
                res.AddRange(MoveRight(matrix, ri, ci,c-1));
                ci+=c-1;
                r--;
                continue;
            }
            switch(i%4) {
                case 0:
                    res.AddRange(MoveRight(matrix, ri, ci, c));
                    ci+=c;
                    r--;
                    break;
                case 1:
                    res.AddRange(MoveBack(matrix, ri, ci, r));
                    ri+=r;
                    c--;
                    break;
                case 2:
                    res.AddRange(MoveLeft(matrix, ri, ci, c));
                    ci-=c;
                    r--;
                    break;
                case 3:
                    res.AddRange(MoveFoward(matrix, ri, ci, r));
                    ri-=r;
                    c--;
                    break;
            }
        }
        res.Add(matrix[ri][ci]);
        IList<int> result = new List<int>(res);
        return result;
    }
    public List<int> MoveRight(int[][] matrix, int xi, int yi, int c) {
        List<int> res = new List<int>();
        for (int i=0;i<c;i++) {
            res.Add(matrix[xi][yi+i]);
        }
        return res;
    }
    public List<int> MoveLeft(int[][] matrix, int xi, int yi, int c) {
        List<int> res = new List<int>();
        for (int i=0;i<c;i++) {
            res.Add(matrix[xi][yi-i]);
        }
        return res;
    }
    public List<int> MoveFoward(int[][] matrix, int xi, int yi, int r) {
        List<int> res = new List<int>();
        for (int i=0;i<r;i++) {
            res.Add(matrix[xi-i][yi]);
        }
        return res;
    }
    public List<int> MoveBack(int[][] matrix, int xi, int yi, int r) {
        List<int> res = new List<int>();
        for (int i=0;i<r;i++) {
            res.Add(matrix[xi+i][yi]);
        }
        return res;
    }
}