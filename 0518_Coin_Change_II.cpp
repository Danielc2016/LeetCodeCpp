class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //DP bottom up
        vector<vector<int>> dp(coins.size() + 1 , vector<int>(amount + 1, -1));
        for(int i = 0; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= amount; i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if( coins[i-1] > j )
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            }
        }
        return dp[coins.size()][amount];
    }
};
