class Solution {
public:
    vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        graph = vector<vector<int>>(numCourses);
        for(auto& pr : prerequisites)
            graph[pr[0]].push_back(pr[1]);
        vector<int> visits(numCourses, 0);
        //states 0: unknown,  1: visiting, 2: visited
        for(int i = 0; i < numCourses; i++)
            if( DFS(i, visits) )
                return false;
        return true;
    }
    
    
    //Use DFS to check if there's a cycle
    bool DFS(int curr , vector<int>& visits)
    {
        if(visits[curr] == 2)
            return false;
        if(visits[curr] == 1)
            return true;
        else
        {
            visits[curr] = 1;
            for(auto& ele : graph[curr])
                if( DFS(ele, visits) )
                    return true;
        }
        visits[curr] = 2;
        return false;
    }
};
