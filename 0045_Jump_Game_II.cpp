//DP
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        vector<int> dp(size, 10001);
        dp[0] = 0;
        for(int i = 0; i < size; i++)
        {
            int index = i+1;
            while(index<i+nums[i]+1)
            {
                if(index >= nums.size())        
                    break;
                dp[index] = min(dp[index], dp[i]+1);
                index++;
            }
        }
        return dp[size-1];
    }
};
