//two ptr
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hist(128,0);
        for(auto& c : t)
            hist[c]++;
        int remain = t.length();
        int left = 0, right = 0;
        int minStart = 0, minLen = INT_MAX;
        //string res = "";
        while( right < s.length() )
        {
            if(--hist[s[right++]] >= 0)
                remain--;
            while(remain == 0)
            {
                if(right - left < minLen)
                {
                    minLen = right -left;
                    minStart = left;
                }
                if(++hist[s[left]] > 0 )
                    remain++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

// 11/04 re-challenge:

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        string res = "";
        int minLen = INT_MAX;
        int count = 0;
        int left = 0, right = 0;
        for(auto& c : t)
        {
            tmap[c]++;
        }
        while(right < s.length())
        {
            if( tmap[s[right]] > 0 )
                count++;
            tmap[s[right]]--;
            if( count == t.length() )
            {
                while(left < right && tmap[s[left]] < 0)
                {
                    tmap[s[left++]]++;
                }
                if(minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    res = s.substr(left, minLen);
                }
                tmap[s[left++]]++;
                count--;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : res ;
    }
};
/*
s = ADOBECODEBANC
t = ABC
   l
s = ADOBECODEBANC
         r



*/
