class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        unordered_set<int> visited;
        vector<vector<int>> mp(n);
        //build graph
        for(auto& ele:edges)
        {
            mp[ele[0]].push_back(ele[1]);
            mp[ele[1]].push_back(ele[0]);
        }
        //set the prev of root to -1
        bool isTree = DFS(mp, visited, 0, -1);
        return isTree && (visited.size()==n);
    }
    
    bool DFS(vector<vector<int>>& mp, unordered_set<int>& visited,
             int curr, int prev)
    {
        if(visited.count(curr))
            return false;
        visited.insert(curr);
        
        for(auto& c : mp[curr])
        {
            if(c == prev)
                continue;
            if(!DFS(mp, visited, c, curr))
                return false;
        }
        return true;
    }
};
