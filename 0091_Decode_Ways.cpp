class Solution {
public:
    int numDecodings(string s) {
        if( s[0] == '0' )
            return 0;
        vector<int> memo(s.length());
        dp(s, memo, 0);
        return memo[0];
    }
    
    int dp(string& s, vector<int>& memo, int i)
    {
        //exit statement
        if(i == s.length())
            return 1;
        if( memo[i] != 0 )
            return memo[i];
        int ans = 0;
        if(  s[i] > '0' && s[i] <= '9')
            ans += dp(s, memo, i + 1);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
            ans += dp(s, memo, i + 2);
        memo[i] = ans;
        return ans;
    }
};
