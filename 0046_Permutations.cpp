class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        //sort(nums.begin(), nums.end());
        vector<int> freq(nums.size(), 0);
        Tracking(nums, path, freq, res);
        return res;
        
    }
    void Tracking(vector<int>& nums,
                  vector<int>& path,
                  vector<int>& freq,
                  vector<vector<int>>& res)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(freq[i]==0)
            {
                path.push_back(nums[i]);
                freq[i] = 1;
                Tracking(nums, path, freq, res);
                freq[i] = 0;
                path.pop_back();
            }
        }
        
    }
};
