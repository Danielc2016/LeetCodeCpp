class Solution {
public:
    //BFS
    int numIslands(vector<vector<char>>& grid)
    {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]=='1')
                {
                    Tracking(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    void Tracking(vector<vector<char>>& grid,
                  int row,
                  int col)
    {
        int n = grid.size(), m = grid[0].size();
        //exit condition
        if( row < 0 || row >= n ||
            col < 0 || col >= m )
            return;
        if(grid[row][col] != '1')
            return;
        
        grid[row][col] = '2';
        Tracking(grid, row-1, col);
        Tracking(grid, row, col-1);
        Tracking(grid, row+1, col);
        Tracking(grid, row, col+1);
    }
};


