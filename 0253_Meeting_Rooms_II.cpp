class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort the intervals by starting time
        // Store the end time into the PQ
        // for every new meeting check if the previous meeting ended
        // if ended, pop that and use the meeting room 
        // update the new meeting end time
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 1;
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < pq.top())
            {
                res++;
                pq.push(intervals[i][1]);
            }
            else if(!pq.empty())
            {
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        return res;
    }
};
