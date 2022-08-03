class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<int> freq(nums.size(), 0);
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        Tracking(nums, path, freq, res);
        
        return res;
    }
    
    void Tracking(vector<int>& nums,
                  vector<int>& path,
                  vector<int>& freq,
                  vector<vector<int>>& res )
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        };
        // TODO
        for(int i = 0; i < nums.size(); ++i)
        {
            if( freq[i] == 0 )
            {
                if(i > 0 and 
                   nums[i] == nums[i-1] and
                   freq[i-1] !=0 )
                {
                    continue;
                }
                freq[i] = 1;
                path.push_back(nums[i]);
                Tracking(nums, path, freq, res);
                path.pop_back();
                freq[i] = 0;
            }
        }
    }
};
