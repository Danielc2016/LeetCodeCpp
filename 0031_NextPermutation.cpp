class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(), k;
        for( k = size-2; k>=0; k--)
        {
            if(nums[k+1] > nums[k])
                break;
        }
        if(k<0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        else
        {
            int i;
            for( i = size-1; i>k; i--)
            {
                if(nums[i]>nums[k])
                {
                    swap(nums[i], nums[k]);
                    break;
                }
            }
            sort(nums.begin()+k+1, nums.end());
        }
    }
};
