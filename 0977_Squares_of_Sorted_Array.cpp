class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        vector<int> res(size, 0);
        for(int i = right; i >=0; i--)
        {
            if( abs(nums[left]) > abs(nums[right]) )
            {
                res[i] = nums[left] * nums[left];
                left++;
            }
            else
            {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};

/*
deque?
left : first element

0, 1, 16,

use the fact: non-decreasing order...
    pointers on left most and right most


*/
