class Solution {
public:
    // Iterative approach
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res = {{}};
        for( auto num : nums)
        {
            int size = res.size();
            for(int i = 0; i < size; i++)
            {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }

    // Back Tracking Approach
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        //vector<int> freq(nums.size(), 0);
        Tracking(nums, path, 0, res);
        res.push_back({});
        return res;
        
    }
    void Tracking(vector<int>& nums,
                  vector<int>& path,
                  int count,
                  vector<vector<int>>& res)
    {
        if(count == nums.size())
            return;
        for(int i = count; i < nums.size(); i++)
        {
            // include this element
            path.push_back(nums[i]);
            res.push_back(path);
            //freq[i] = 1;
            Tracking(nums, path, i+1, res);
            path.pop_back();
        }
    }


};

