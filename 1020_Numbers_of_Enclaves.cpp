class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = (int) grid.size(), n = (int) grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            if( grid[i][0] == 1)
            {
                dfs(grid, i, 0);
            }
            if( grid[i][n-1] == 1)
            {
                dfs(grid, i, n - 1);
            }
        }
        for(int i = 1; i < n - 1; i++)
        {
            if( grid[0][i] == 1 )
            {
                dfs(grid, 0 , i);
            }
            if( grid[m-1][i] == 1 )
            {
                dfs(grid, m - 1, i);
            }
        }
        for(int i = 1; i < m - 1; i++)
        {
            for(int j = 1; j < n - 1; j++)
            {
                if(grid[i][j] == 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        // exit condition
        if(row < 0 || row >= grid.size() ||
           col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return;
        if( grid[row][col] == 1)
        {
            grid[row][col] = 2;
            dfs(grid, row - 1, col);
            dfs(grid, row + 1, col);
            dfs(grid, row, col - 1);
            dfs(grid, row, col + 1);
        }
    }
};

/*

DFS

*/
