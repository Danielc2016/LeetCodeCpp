class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = (int) nums.size();
        vector<int> res;
        deque<int> pq;
        for(int i = 0; i < size; i++)
        {
            while( !pq.empty() && nums[i] > nums[pq.back()] )
            {
                pq.pop_back();
            }
            pq.push_back(i);
            while( !pq.empty() && i - k >= pq.front() )
            {
                pq.pop_front();
            }
            if( i >= k -1)
            {
                res.push_back(nums[pq.front()]);
            }
        }
        return res;
    }
};

/*
priority queue: (need a pair)
1 2 3,2,3,4, 5, 6?

deque:

brute force:
a vector with size k:
    every iteration: 
        - erase front
        - push back new element
        - 

*/
