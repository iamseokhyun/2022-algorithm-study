public class Solution {
    public void Rotate(int[][] matrix) {
        int size = matrix.Length-1;
        while (size>-1) {
            Rotate(ref matrix, size);
            size-=2;
        }
    }
    public void Rotate(ref int[][] matrix, int size) {
        if (size==0) {
            return;
        }
        int[] mem = new int[size];
        int tmp = 0;
        int strt = (matrix.Length-size)/2;
        for (int i=0;i<size; i++) {
            mem[i] = matrix[strt+i][strt+size]; //Right side를 저장.
            matrix[strt+i][strt+size] = matrix[strt+size][strt+i]; // Right side를 Front Side로 치환
        }
        for (int i=0;i<size; i++) { //Right Side -> Bottom Side
            tmp=matrix[strt+size][strt+size-i];
            matrix[strt+size][strt+i] = mem[i];
            mem[i]=tmp;
        }
        for (int i=0;i<size; i++) { //Bottom side -> Left side
            tmp=matrix[strt+size-i][strt];
            matrix[strt-i][strt+size] = mem[i];
            mem[i]=tmp;
        }
        for (int i=0;i<size; i++) { //Bottom side -> Left side
            matrix[strt][strt+i] = mem[i];
        }
    }
}