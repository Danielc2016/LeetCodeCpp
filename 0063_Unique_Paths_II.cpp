// Dynamic Programming
// Runtime 6ms
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int DP[m][n];
        DP[0][0] = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i==0 || j==0)
                {
                    if(obstacleGrid[i][j]!=1)
                    {
                        if(i > 0 )
                            DP[i][j] = DP[i-1][j];
                        else if( j > 0)
                            DP[i][j] = DP[i][j-1];
                        else
                            DP[i][j] = 1;
                    }
                    else
                    {
                        DP[i][j] = 0;
                    }
                }
                else
                {
                    if(obstacleGrid[i][j]!=1)
                    {
                        DP[i][j] = 
                        (obstacleGrid[i][j-1] ? 0 : DP[i][j-1])
                      + (obstacleGrid[i-1][j] ? 0 : DP[i-1][j]) ;
                    }
                    else
                        DP[i][j] = 0;
                }
            }
        }
        return DP[m-1][n-1];
    }
};
