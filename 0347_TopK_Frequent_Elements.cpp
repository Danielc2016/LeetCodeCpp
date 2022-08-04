class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        typedef pair<int, int> pairs;
        unordered_map<int, int> freq_map;
        vector<int> res;
        for( auto i : nums)
        {
            freq_map[i]++;
        }
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        for( auto i : freq_map)
        {
            int element = i.first, count = i.second;
            pq.push(make_pair(count, element));
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
