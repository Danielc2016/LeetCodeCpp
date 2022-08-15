class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int index = 0;
        int size = intervals.size();
        while(index < size && intervals[index][1] < newInterval[0])
        {
            res.push_back(intervals[index++]);
        }
        while(index < size && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        res.push_back(newInterval);
        while(index < size)
        {
            res.push_back(intervals[index++]);
        }
        return res;
    }
};
