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
