public class Solution {
    public void SetZeroes(int[][] matrix) {
        int r = matrix.Length;
        int c = 0;
        if (r>0) {
            c = matrix[0].Length;
        }
        bool[] rowFlag = new bool[r];
        bool[] colFlag = new bool[c];
        for (int i =0;i<r;i++) {
            for (int j = 0;j<c;j++) {
                if (matrix[i][j]==0) {
                    rowFlag[i]=true;
                    colFlag[j]=true;
                }
            }
        }
        for (int i =0;i<r;i++) {
            if (rowFlag[i]) {
                for (int j =0;j<c;j++) {
                    matrix[i][j]=0;
                }
            }
        }
        for (int j = 0;j<c;j++) {
            if (colFlag[j]) {
                for (int i =0;i<r;i++) {
                    matrix[i][j]=0;
                }
            }
        }
    }
}