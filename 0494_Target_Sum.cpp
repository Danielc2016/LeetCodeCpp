class Solution {
public:
    //Recursive solution
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return (nums[0] == target || -nums[0] == target ) ? 1 : 0;
        return findTarget(nums, 0, target);
    }
    int findTarget(vector<int>& nums, int indx, int target)
    {
        if(indx >= nums.size())
        {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        //if(nums[indx] > target)
        return findTarget(nums, indx + 1, target + nums[indx])
             + findTarget(nums, indx + 1, target - nums[indx]);
    }
};
