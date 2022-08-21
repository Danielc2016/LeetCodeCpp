class Solution {
public:
    typedef pair<string, double> pa;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pa>> mp; 
        // Graph contains key->key and a value
        // make dist to max for each iteration ?
        vector<double> res;
        //build graph
        for(int i = 0; i < equations.size(); i++)
        {
            const double k = values[i];
            mp[equations[i][0]].push_back({equations[i][1], k });
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / k });
        }
        for(auto& ele : queries)
        {
            if(!mp.count(ele[0]) || !mp.count(ele[1]))
            {
                res.push_back( -1.0 );
                continue;
            }
            unordered_set<string> visited;
            double ans = walk(mp, visited, ele[0], ele[1]);
            res.push_back(ans);
        }
        return res;
    }


    double walk(unordered_map<string, vector<pa>>& mp,
                unordered_set<string>& visited, string u, string v)
    {
        if( u==v )
            return 1.0;
        visited.insert(u);
        for(auto& path : mp[u] )
        {
            if(visited.count(path.first))
                continue;
            double t = walk(mp, visited, path.first, v);
            if( t > 0 )
                return ( t * path.second );
        }
        return -1.0;
    }
};

