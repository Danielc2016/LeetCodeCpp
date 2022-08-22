class Solution {
public:
    int rob(vector<int>& nums) {
        // base case
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int memo[nums.size()], dp[nums.size()];
        memo[0] = nums[0];
        memo[1] = max(memo[0], nums[1]);
        dp[0] = 0, dp[1] = nums[1];
        //memo goes from 0 -> n-2
        //dp goes from 1 -> n-1
        for(int i = 2; i < nums.size(); i++)
        {
            memo[i] = max(memo[i-1], memo[i-2] + nums[i]);
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(memo[nums.size()-2], dp[nums.size()-1]);
    }
};
