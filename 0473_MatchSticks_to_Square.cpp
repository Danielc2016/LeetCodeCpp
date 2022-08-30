class Solution {
 //Time Exceeds Limit...
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() <= 3)
            return false;
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if( total % 4 != 0 )
            return false;
        total = total / 4;
        vector<bool> visited(matchsticks.size());
        return dfs(matchsticks, visited, 0, 0, 0, total);
    }
    
    bool dfs(vector<int>& matchsticks,vector<bool>& visited,
             int curr, int group, int sum, int& target)
    {
        if(group == 4)
            return true;
        if(sum > target)
            return false;
        if(sum == target)
            return dfs(matchsticks, visited, 0, group+1, 0, target);
        for(int i = 0; i < matchsticks.size(); i++)
        {
            if(visited[i])
                continue;
            visited[i] = true;
            if( dfs(matchsticks, visited, i + 1, group,
                    sum + matchsticks[i], target) )
                return true;
            visited[i] = false;
        }
        return false;
    }
};
