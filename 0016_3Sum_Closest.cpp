class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        sort(nums.begin(), nums.end());
        int sum = 0, res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < size - 2; i++)
        {
            int mid = i + 1; 
            right = size - 1;
            while(mid < right)
            {
                sum = nums[i] + nums[mid] + nums[right];
                if( abs(sum - target) < abs(res - target) )
                    res = sum;
                if(sum > target)
                    right--;
                else
                    mid++;
            }
        }
        return res;
    }
};

/*
1. sort
2. two pointer


-2,    -1, 0, 1, 5,
left             right


target: 0

left: -2
right: 5

Time Comp: O(N^2)

*/
