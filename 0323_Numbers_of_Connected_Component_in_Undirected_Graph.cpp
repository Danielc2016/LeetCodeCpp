class Solution {
public:
    //BFS
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> visited(n, 0);
        vector<vector<int>> mp(n);
        for(auto& ele:edges)
        {
            mp[ele.front()].push_back(ele.back());
            mp[ele.back()].push_back(ele.front());
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                ans++;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    for(auto& c : mp[temp])
                    {
                        if(!visited[c])
                        {
                            q.push(c);
                            visited[c] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
