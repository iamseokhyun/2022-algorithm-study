vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int cnt = 0, turn = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans(m*n);  
    int row=0, col=-1, bdry = 0;
    while(cnt < m*n){
        switch((++turn)%4){  
            case 1:
            {   while(col<n-1-bdry)
                    ans[cnt++] = matrix[row][++col];
                    break;
            }
            case 2:
            {   while(row<m-1-bdry)
                    ans[cnt++] = matrix[++row][col];
                    break;
            }
            case 3:
            {   while(col>bdry)
                    ans[cnt++] = matrix[row][--col];
                    break;
            }
            case 0:
            {   bdry++;
                while(row>bdry)
                    ans[cnt++] = matrix[--row][col];
                    break;
            }
        }
    }
    return ans;    
}

/*
- cnt: count for unoverlapped elements of matrix (if cnt == m*n, all elements of matrix are checked)
- turn: turn%4 means which direction are we going to skim elements.
- bdry: bdry means we are going to skim bdry th boundary of the matrix.
*/
