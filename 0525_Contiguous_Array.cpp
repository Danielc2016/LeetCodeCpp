class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int res = 0;
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] == 1)
            {
                ++sum;
            }
            else
            {
                --sum;
            }
            if(mp.count(sum))
            {
                res = max(res, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return res;
    }
};
/*
prefix sum:
using map: prefix sum --> index

subarray sum[j:i] --> prefix[i] - prefix[j-1]
*/
