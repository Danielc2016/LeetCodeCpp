class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        int mid = 0;
        while( left <= right )
        {
            mid = left + (right - left)/2;
            if( nums[mid] > target )
            {
                if(nums[left] > target && nums[right] < nums[mid] )
                    //search for edge case
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                if(nums[right] < target && nums[left] > nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

/*
4, 5, 6, 7, 0, 1,  2
0                  6
l                  r
target = 0

mid = 7
    nums[mid] > target:
        1. nums[left] > target: 
                left = mid + 1
        2. right = mid - 1
    nums[mid] < target:
        1. nums[right] < target:
                right = mid - 1
        2. left = mid + 1
    return mid
    
4, 5, 6, 7, 8, 1, 2, 3

target = 8
mid = 7


*/
