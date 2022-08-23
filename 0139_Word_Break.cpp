class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //unordered_map<string, int> mp;
        int size = s.length();
        vector<bool> dp(size+ 1, false);
        dp[size] = true;
        for(int i = size - 1; i >=0 ; i--)
        {
            for(auto& str : wordDict)
            {
                if(i + str.length() <= size && s.substr(i, str.length()) == str)
                    dp[i] = dp[i + str.length()];
                if(dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
