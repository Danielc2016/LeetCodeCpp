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
