class Solution {
public:
    //Bellman-Ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n,1e6);
        cost[src]=0;
        for(int i = 0; i <= k; i++)
        {
            vector<int> temp = cost;
            for(auto& ele : flights)
            {
                temp[ele[1]] = min(temp[ele[1]], cost[ele[0]] + ele[2]);
            }
            cost = temp;
        }
        return cost[dst]==1e6 ? -1 : cost[dst];
    }
};
