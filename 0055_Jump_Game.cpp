//Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int goal = size - 1;
        for(int i = size -1; i >= 0; i--)
        {
            if(i + nums[i] >= goal)
                goal = i;
        }
        return 0==goal;   
    }
};

//DP
// Time exceeds limit...
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        return DP(0, nums);
    }
    bool DP(int n, vector<int>& nums)
    {
        if(n + nums[n] >= nums.size() - 1)
            return true;
        for(int i = 1; i <= nums[n]; ++i)
        {
            if(DP(n + i, nums))
                return true;
        }
        return false;
    }
};


//DP without recursion;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
         // Only One Element , so we do not have to jump anywhere
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            // traversing backward to see if we can reach ith index
            {
                if (dp[j] && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};
