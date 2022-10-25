class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFSTracking(candidates, target, 0, path, res);
        return res;
        
    }
    void DFSTracking(vector<int>& candidates, int target, int count,
                     vector<int>& path, vector<vector<int>>& res)
    {
        // exit condition
        if( target < 0 || path.size() + 1 > 40)
            return;
        // confirm state
        if( target == 0 )
        {
            res.push_back(path);
            return;
        }
        for(int i = count; i < (int) candidates.size(); i++)
        {
            path.push_back( candidates[i] );
            DFSTracking(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
};

