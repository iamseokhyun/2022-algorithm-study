vector<vector<int>> direction = {{-1,0}, {1,0}, {0,1}, {0,-1}};
void findWay(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, int m, int n){
    if(visited[row][col]) return;
    visited[row][col] = true;
        
    for(auto way : direction){
        int y = row + way[0], x = col + way[1];
        if(y<0 || y>=m || x<0 || x>=n || heights[row][col] > heights[y][x])
            continue;
        findWay(heights, visited, y, x, m, n);
        }
    }
   
 vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> canPacific(m, vector<bool>(n));
    vector<vector<bool>> canAtlantic(m, vector<bool>(n));
        
    // findWay(DFS)
    for(int row=0;row<m;row++){
        findWay(heights, canPacific, row, 0, m, n);
        findWay(heights, canAtlantic, row, n-1, m, n);
    }
    for(int col=0;col<n;col++){
        findWay(heights, canPacific, 0, col, m, n);
        findWay(heights, canAtlantic, m-1, col, m, n);
    }
        
    vector<vector<int>> ans;
    for(int row=0;row<m;row++)
        for(int col=0;col<n;col++)
            if(canPacific[row][col] && canAtlantic[row][col])
                ans.push_back({row, col});
                    
    return ans;
}
