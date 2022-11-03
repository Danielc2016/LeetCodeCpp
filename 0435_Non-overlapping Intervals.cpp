

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {    
        int res = 0, prev;
        int n = intervals.size();
        auto comp = [&] (vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0] ||
                 ( a[0] == b[0] && a[1] < b[1]);
        };
        sort(intervals.begin(), intervals.end(), comp);
        prev = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if( intervals[i][0] >= prev )
                prev = intervals[i][1];
            else
            {
                res++;
                prev = min(prev, intervals[i][1]);
            }
        }
        return res;
    }
    
};
/*
[1,2] [1,3] [2,3] [3,4]


*/
