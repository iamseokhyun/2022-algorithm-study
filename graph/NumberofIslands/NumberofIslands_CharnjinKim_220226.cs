public class Solution
{
    public int cnt = 0;
    public int NumIslands(char[][] grid)
    {
        for (int r = 0; r < grid.Length; r++)
        {
            for (int c = 0; c < grid[0].Length; c++)
            {
                if (grid[r][c] == '1')
                {
                    ScanLand(grid, r, c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    public bool isOne(char[][] grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.Length || c >= grid[0].Length)
        {
            //do nothing;
            return false;
        }
        if (grid[r][c] == '1')
        {
            grid[r][c] = '0';
            return true;
        }
        else
        {
            return false;
        }
    }
    public void ScanLand(char[][] grid, int r, int c)
    {
        //onsole.WriteLine($"Scanned {r}, {c}");

        if (isOne(grid, r + 1, c))
        {
            ScanLand(grid, r + 1, c);
        }
        if (isOne(grid, r - 1, c))
        {
            ScanLand(grid, r - 1, c);
        }
        if (isOne(grid, r, c + 1))
        {
            ScanLand(grid, r, c + 1);
        }
        if (isOne(grid, r, c - 1))
        {
            ScanLand(grid, r, c - 1); ;
        }
    }
}