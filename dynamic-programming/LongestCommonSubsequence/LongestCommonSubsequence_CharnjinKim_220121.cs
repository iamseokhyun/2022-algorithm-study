public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        int m = text1.Length;
        int n = text2.Length;
        int[,] maxnum = new int[m+1,n+1];
        for (int k = 1;k<=m;k++) {
            for (int j=1;j<=n;j++) {
                Checkif(text1,text2,k,j,ref maxnum);
            }
        }
        return maxnum[m,n];
    }
    public void Checkif(string text1, string text2, int m, int n, ref int[,] maxnum) {
        int diag=maxnum[m-1,n-1];
        int up = maxnum[m,n-1];
        int left = maxnum[m-1,n];
        if (text1[m-1].Equals(text2[n-1])) {
            maxnum[m,n]=diag+1;
        }else {
            maxnum[m,n]= (up>left) ? up : left;    
        }
    }
}