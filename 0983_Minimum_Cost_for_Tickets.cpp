class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366 , 365000);
        unordered_map<int, int> mp;
        mp[1] = costs[0];
        mp[7] = costs[1];
        mp[30] = costs[2];
        dp[0] = 0;
        for(int i = 1; i < 366; i++)
        {
            if( find(days.begin(), days.end(), i) == days.end() )
            {
                dp[i] = dp[i-1];
                continue;
            }
            for(auto& m : mp)
            {
                dp[i] = min(dp[i], dp[max(0, i-m.first)] + m.second);
            }
        }
        return dp[365];
    }
};
