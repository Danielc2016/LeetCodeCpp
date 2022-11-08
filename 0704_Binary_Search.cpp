class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if( nums[mid] > target)
            {
                high = mid - 1;
            }
            else if( nums[mid] < target )
            {
                low = mid + 1;
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
-1, 0, 3, 5, 9, 12

0                 5

l                 h

while( l <= h )
mid = l + (h- l)/2;
nums[mid] > target:
    h = mid -1 ;
nums[mid] < target
    l = mid + 1;


*/
