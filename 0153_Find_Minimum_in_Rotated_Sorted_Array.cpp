class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size() - 1;
        int left = 0, right = size;
        while(left < right )
        {
            int mid = left + (right - left) / 2;
            if(nums[right] < nums[left])
            {
                if(nums[mid] > nums[left])
                    left = mid + 1;
                else
                    left = left + 1;
                //Can we make it better?
            }
            else if(nums[right] > nums[left])
            {
                break;
            }
        }
        return nums[left];
    }
};
