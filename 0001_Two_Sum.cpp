class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        //vector<int>res;
        for(int i = 0; i < nums.size(); i++)
        {
            if( mp.find(target - nums[i])!= mp.end() )
            {
                int prev = mp[target -nums[i]];
                //res.push_back(prev);
                //res.push_back(i);
                return {prev, i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
