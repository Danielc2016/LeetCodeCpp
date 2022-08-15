class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int size = intervals.size();
        if(size <=1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 1; i < size; i++)
        {
            if(intervals[i][0] > intervals[i-1][1])
                res.push_back(intervals[i-1]);
            else
            {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            }
        }
        res.push_back(intervals[size-1]);
        return res;
    }
};
