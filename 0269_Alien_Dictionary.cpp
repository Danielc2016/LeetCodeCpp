class Solution {
public:
    string alienOrder(vector<string>& words) {
        //build graph
        unordered_map<char, unordered_set<char>> g;
        for(int i = 1; i < words.size(); i++)
        {
            string w1 = words[i-1];
            string w2 = words[i];
            for(int j = 0; j < min(w1.length(), w2.length()); j++)
            {
                if(w1[j] != w2[j])
                {
                    g[w1[j]].insert(w2[j]);
                    break;
                }
                if(j == min(w1.length(), w2.length()) - 1
                  && w1.length() > w2.length())
                    return "";
            }
        }
        //visited
        unordered_map<char, int> visited;
        for (auto& word : words) {
            for (char ch : word) {
                visited[ch] = 0;
            }
        }
        string res = "";
        for(auto& [ch, visits] : visited)
        {
           if( visits == 0 )
           {
               bool hasCycle = dfs(g, visited, res, ch);
               if(hasCycle)
                   return "";
           }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool dfs(unordered_map<char, unordered_set<char>>& g,
             unordered_map<char, int>& visited,
             string& order,
             char ch)
    {
        visited[ch] = 1;
        for(auto neighbor : g[ch])
        {
            if(visited[neighbor] == 1)
                return true;
            if (visited[neighbor] == 0)
            {
                if(dfs(g, visited, order, neighbor))
                    return true;
            }
        }
        visited[ch] = 2;
        order.push_back(ch);
        return false;
    }
};

