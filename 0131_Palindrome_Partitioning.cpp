bool isValid(string s);
void tracking(string s, int right,
              vector<string>& path, vector<vector<string>>& res);
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        vector<vector<string>> res;
        tracking(s, 0, path, res);
        return res;
        
    }
    
    void tracking(string s, int right,
                  vector<string>& path, vector<vector<string>>& res)
    {
        if( right >= (int)s.length() )
        {
            res.push_back(path);
            return;
        }
        for(int i = right; i < (int)s.length(); i++)
        {
            if( isValid( s.substr(right, i - right + 1) ) )
            {
                path.push_back( s.substr(right, i - right + 1) );
                tracking( s, i + 1, path, res );
                path.pop_back();
            }
        }
    }
    
    bool isValid(string s)
    {
        int i = 0, j = (int)s.length() - 1;
        while( i <= j )
        {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};


/*
back-tracking
aabbc:
single:
a, a, b, b, c
double:
aa, bb ,c
triple:

*/
