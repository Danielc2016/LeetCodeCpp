class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        bool singlechar = false;
        for(auto ch : s)
        {
            mp[ch]++;
        }
        for(auto& element : mp)
        {
            if(element.second % 2 == 0)
            {
                res += element.second;
            }
            else
            {
                res += element.second - 1;
                singlechar = true;
            }
        }
        if(singlechar)
            res++;
        return res;
    }
};
