class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> mp;
        for(auto& c : s1)
        {
            mp[c]++;
        }
        int left = 0, right = 0;
        int cValid = 0;
        while( right < s2.length() )
        {
            if( --mp[s2[right]] >= 0 )
            {
                cValid++;
            }
            right++;
            while( right - left >= s1.length() )
            {
                if( cValid == s1.length() )
                    return true;
                if( ++mp[s2[left]] > 0 )
                    cValid--;
                left++;
            }
        }
        return false;
    }
};
