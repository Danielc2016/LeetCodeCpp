class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 1, size = s.length();
        if(size < 2) return size;
        int i = 0, j = 0;
        while(j<size)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                ans=max(ans,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
        
    }
};
