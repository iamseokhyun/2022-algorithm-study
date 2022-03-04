public class Solution {
    public bool Exist(char[][] board, string word) {
        int r = board.Length;
        int c = 0;
        if (r>0) {
            c = board[0].Length;
        }
        char fstWrd = word[0];
        for(int i =0;i<r;i++) {
            for (int j = 0; j<c;j++) {
            bool[,] save = new bool[r,c];
                if (board[i][j].Equals(fstWrd)) {
                    save[i,j]=true;
                    if (Exist(board, word, 1, ref save, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public bool Exist(char[][] board, string word, int idx, ref bool[,] save, int r, int c) {
        if (word.Length==idx) {
            return true;
        }
        char target = word[idx];
        if (c+1<board[0].Length && board[r][c+1].Equals(target) && !save[r,c+1]) {
            save[r,c+1] = true;
            if (Exist(board, word, ++idx, ref save, r, c+1)) {
                return true;
            } else {
                save[r,c+1]=false;
                idx--;
                return false;
            }
        } else if (c-1>-1 && board[r][c-1].Equals(target) && !save[r,c-1]) {
            save[r,c-1]=true;
            if (Exist(board, word, ++idx, ref save, r, c-1)) {
                return true;
            } else {
                save[r,c-1]=false;
                idx--;
                return false;
            }
        } else if (r+1<board.Length && board[r+1][c].Equals(target) && !save[r+1,c]) {
            save[r+1,c]=true;
            if (Exist(board, word, ++idx, ref save, r+1, c)) {
                return true;
            } else {
                save[r+1,c]=false;
                idx--;
                return false;
            }
        } else if (r-1>-1 && board[r-1][c].Equals(target) && !save[r-1,c]) {
            save[r-1,c]=true;
            if (Exist(board, word, ++idx, ref save, r-1, c)) {
                return true;
            } else {
                save[r-1,c]=false;
                idx--;
                return false;
            }
        } else {
            return false;
        }
    }
}