class Solution {
public:
    // sliding window using two vectors
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> countS(26, 0), countP(26, 0);
        int size_p = p.size();
        for( auto& val : p )
            countP[val-'a']++;
        
        for(int i = 0; i < s.size(); i++)
        {
            if( i >= size_p )
                countS[ s[i-size_p] - 'a']--;
            
            countS[s[i] - 'a']++;
            
            if(countS == countP)
                res.push_back(i + 1 - size_p);
        }
        return res;
    }
};
