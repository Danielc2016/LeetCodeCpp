class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        //build graph
        vector<vector<int>> g;
        g = vector<vector<int>>(numCourses, vector<int>());
        for(auto& cla : prerequisites)
        {
            g[cla[0]].push_back(cla[1]);
        }
        //visited nodes and result
        vector<int> visited(numCourses, 0);
        vector<int> res;
        //topological sort
        for(int i = 0; i < numCourses; i++)
        {
            if( visited[i] == 0 )
            {
                if(dfs(g, visited, res, i))
                    return {};
            }
        }
        //no need to reverse!!
        //reverse(res.begin(), res.end());
        return res;
    }
    
    bool dfs(vector<vector<int>> & g,
             vector<int>& visited, vector<int>& res, int curr)
    {
        visited[curr] = 1;
        for(auto& pre : g[curr])
        {
            if(visited[pre]==1)
                return true;
            if(visited[pre]==0)
            {
                bool hasCycle = dfs(g, visited, res, pre);
                if(hasCycle)
                    return true;
            }
        }
        visited[curr] = 2;
        res.push_back(curr);
        return false;
    }
};
