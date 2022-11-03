class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> mp;
        for(auto& c : s)
        {
            mp[c]++;
        }
        for(auto& c : t)
        {
            if(!mp[c] || mp[c] < 0)
                return false;
            else
                mp[c]--;
        }
        return true;
    }
};

