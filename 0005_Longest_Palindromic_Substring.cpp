class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        if(size == 1) return s;
        string res = "";
        int maxLen = 0;
        for(int i = 0; i < size; i++)
        {
            // check for left and right ptr are same char
            int left = i, right = i;
            while(left >= 0 && right < size && s[left]==s[right])
            {
                if( right - left + 1 > maxLen )
                {
                    maxLen = right - left + 1;
                    res = s.substr(left, maxLen);
                }
                left--, right++;
            }
            // or check for longest continuous char
            left = i, right = i+1;
            while(left >= 0 && right < size && s[left]==s[right])
            {
                if( right - left + 1 > maxLen )
                {
                    maxLen = right - left + 1;
                    res = s.substr(left, maxLen);
                }
                left--, right++;
            }
        }
        return res;
    }
};
