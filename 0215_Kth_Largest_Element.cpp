class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return quickSelect(nums, target, 0, nums.size() - 1);
    }
    int quickSelect(vector<int>& nums, int& target,
                    int left, int right)
    {
        int pivot = nums[right];
        int p = left;
        for(int i = left; i < right; i++)
        {
            if(nums[i] < pivot)
            {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[right]);
        if( target > p )
            return quickSelect(nums, target, p + 1, right);
        else if( target < p )
            return quickSelect(nums, target, left, p - 1);
        else
            return nums[p];
    }
};
