class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<int> Scount(26, 0);
        int left = 0;
        for(int j = 0; j < s.size(); j++)
        {
            Scount[s[j] - 'A']++;
            int maxFreq = *max_element(Scount.begin(), Scount.end());
            while( j - left + 1 - maxFreq > k)
            {
                Scount[s[left] - 'A']--;
                left++;
            }
            res = max(res, (j - left + 1));
        }
        return res;
    }
};
