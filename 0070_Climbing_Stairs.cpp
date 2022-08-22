class Solution {
public:
    int climbStairs(int n) {
        int memo[46] = {0};
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
        if(n < 3)
            return n==2 ? memo[2] : memo[1];
        for(int i = 4; i <= n; i++)
        {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};
