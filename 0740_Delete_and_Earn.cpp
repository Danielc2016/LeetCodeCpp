class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //Using House Robber DP
        int size = nums.size();
        if(size == 1) return nums[0];
        int m = *max_element(nums.begin(), nums.end());
        vector<int> points(m + 1, 0);
        vector<int> memo(m + 1, 0);
        for(auto& num : nums)
            points[num] += num;
        memo[0] = points[0], memo[1] = points[1];
        for(int i = 2; i <= m; i++)
        {
            memo[i] = max(memo[i-1], memo[i-2] + points[i]);
        }
        return memo[m];
    }
};

/*
sort first?
** Brute Force

        if(size == 1) return nums[0];
        unordered_map<int, int> mp;
        int res = 0;
        int ans = 0;
        for(auto& num : nums)
        {
            mp[num]++;
        }
        for(auto& m : mp)
        {
            unordered_map<int, int> temp;
            temp = mp;
            res = m.first * m.second;
            temp[m.first-1] = 0;
            temp[m.first+1] = 0;
            temp[m.first] = 0;
            for(auto& t : temp)
            {
                if(t.second != 0)
                {
                    res += t.first * t.second;
                    temp[t.first - 1] = 0;
                    temp[t.first + 1] = 0;
                    temp[t.first] = 0;
                }
            }
            ans = max(res, ans);
        }
        return ans;
*/
