void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();        
    int temp;                
    for(int s=0;s<n/2;s++)  // s means sth shell of the matrix
        for(int e=0;e<n-2*s-1;e++){  // e means eth element along the edge of the sth shell              
            temp = matrix[s][s+e];
            matrix[s][s+e] = matrix[n-1-(s+e)][s];
            matrix[n-1-(s+e)][s] = matrix[n-1-s][n-1-(s+e)];
            matrix[n-1-s][n-1-(s+e)] = matrix[s+e][n-1-s];     
            matrix[s+e][n-1-s] = temp;            
    }    // swap 4 elements (clockwise rotation)
}

/*
- First for loop(iteration with variable s) is used to 
  make subproblems of rotation, by dividing matrix with sth(0 ~ n/2) shells.
- Second for loop(iteration with variable e) is used to solve subproblem of 
  rotation at sth shell. There are n-2s-1 groups of elements(length of the shell¡¯s
  edge is n-2s) needed to be rotated.
- Time Complexity: O(n^2)
- Space Complexity: O(1)
*/
