class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> pa;
        vector<vector<pa>> g(n + 1); //Graph
        vector<int> dist(n + 1, INT_MAX); //Distance
        vector<bool> visited(n + 1, false); //Visited
        int res = 0;
        priority_queue<pa, vector<pa>, greater<pa>> pq;
        dist[k] = 0, dist[0] = 0;
        for(auto& path : times)
        {
            g[path[0]].push_back(make_pair(path[1], path[2]));
        }
        
        pq.push({0, k});
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            if(visited[node])
                continue;
            visited[node] = true;
            for(auto& ele : g[node])
            {
                if(dist[ele.first] > dist[node] + ele.second)
                {
                    dist[ele.first] = dist[node] + ele.second;
                    pq.push({dist[ele.first], ele.first});
                }
            }
        }
        for(auto w : dist)
        {
            res = max(w, res);
        }
        return res == INT_MAX ? -1 : res;
    }
};
