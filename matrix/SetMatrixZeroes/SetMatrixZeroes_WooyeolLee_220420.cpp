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


void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
                
    // marking process        
    bool row0 = false; // mark whether there is zero index at row0        
    for(int j=0;j<n;j++)
        if(matrix[0][j] == 0) {
            row0 = true;  
            break;          
        }      
    for(int i=1;i<m;i++) 
        for(int j=0;j<n;j++) 
            if(matrix[i][j] == 0){    
                matrix[i][0] = 0;     
                matrix[0][j] = 0;     
            }                
   
    // setting cell values to zero    
    for(int i=m-1;i>0;i--)    
        for(int j=n-1;j>=0;j--)     
            if(!matrix[i][0] || !matrix[0][j])        
                matrix[i][j] = 0;    
    if(row0)       
        for(int j=0;j<n;j++)    
            matrix[0][j] = 0;     
} // S.C. O(1) algorithm

/*
- first row and column are used to mark whether each row or column are going to be set to zero. 
  Especially for row 0 AND col 0, matrix[0][0] only means whether column 0 is going to be set to zero. 
  To mark that condition of row 0, I used row0 variable(bool type).
- After marking, I set each cell value to zero if needed. To prevent this procedure leads to discrepancies, 
  I iterate it from last row, last column of the matrix to first column, second row of the matrix. 
  (Update first column at last) Then check the first row by row0.
- Time Complexity : O(mn) by marking&revising procedure
- Space Complexity : O(1) by one row0 variable
*/
