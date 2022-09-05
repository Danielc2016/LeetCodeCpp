class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length()+1, n = p.length()+1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(dp, s, p, 0, 0);
    }
    
    bool dfs(vector<vector<int>>& dp, string& s, string& p,
             int i, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i >= s.length() && j >= p.length())
            return true;
        if(j >= p.length())
            return false;
        bool match = (i < s.length() && ( s[i] == p[j] || p[j] == '.' ) );
        if (j + 1 < p.length() && p[j+1] == '*')
        {
            if( dfs(dp, s, p, i, j+ 2) || ( match && dfs(dp, s, p, i+1, j) ) ) 
            {
                dp[i][j] = 1;
                return dp[i][j];
            }
            else
            {
                dp[i][j] = 0;
                return dp[i][j];
            }
        }
        if(match)
        {
            dp[i][j] = dfs(dp, s, p, i+1, j+1);
            return dp[i][j];
        }
        return false;
    }
};
