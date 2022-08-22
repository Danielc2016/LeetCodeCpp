class Solution {
public:
    int countSubstrings(string s)
    {
        int res = 0, size = s.length();
        //vector<int> dp(size, 1);
        for(int i = 0; i < size; i++)
        {
            int left = i, right = i;
            while(left >= 0 && right < size && s[left]==s[right])
            {
                res++;
                left--, right++;
            }
            left = i, right = i + 1;
            while(left >= 0 && right < size && s[left]==s[right])
            {
                res++;
                left--, right++;
            }
        }
        return res;
    }
};
