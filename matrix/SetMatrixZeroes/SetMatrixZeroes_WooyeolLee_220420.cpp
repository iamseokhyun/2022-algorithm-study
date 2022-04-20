void setZeroes(vector<vector<int>>& matrix) {        
    int m = matrix.size(), n = matrix[0].size();        
    vector<bool> row(m), col(n);        
    for(int i=0;i<m;i++)     
        for(int j=0;j<n;j++)   
            if(matrix[i][j] == 0){     
                row[i] = true;    
                col[j] = true;      
            }

    for(int i=0;i<m;i++)
        if(row[i])
            for(int j=0;j<n;j++)   
                matrix[i][j] = 0;
    for(int j=0;j<n;j++)
        if(col[j])
            for(int i=0;i<m;i++)
                matrix[i][j] = 0;    
} // SC: O(m+n) algorithm

/*
- Bool vectors row, col represent whether there is at least one element 0.
- First for loop: explore matrix to find element zero and save it to vector row, col.
- Second and third for loops: make all elements in rows and cols which are detected at exploring procedure to zero.(revising procedure)
- Time Complexity : O(mn) by exploring&revising procedure
- Space Complexity : O(m+n) by two bool vectors
*/
