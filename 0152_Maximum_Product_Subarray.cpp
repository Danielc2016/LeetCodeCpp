class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int res = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if( nums[i] == 0)
            {
                curMax = 1, curMin = 1;
                continue;
            }
            int temp = curMax * nums[i];
            curMax = max(curMax * nums[i], max( curMin * nums[i], nums[i]) );
            curMin = min( temp, min( curMin * nums[i], nums[i] ) );
            res = max( res, curMax);
        }
        return res;
    }
};

