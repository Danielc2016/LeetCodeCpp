class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //sort(stones.begin(), stones.end());
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() >= 2)
        {
            int L1 = pq.top();
            pq.pop();
            int L2 = pq.top();
            pq.pop();
            if(L1 > L2)
            {
                pq.push(L1-L2);
            }
        }
        if(pq.size() != 0)
            return pq.top();
        else
            return 0;
    }
};
