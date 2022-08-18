class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int k;
        for(int i = 0; i <= n; i++)
        {
            k = i;
            while(k)
            {
                k &= k-1;
                ans[i]++;
            }
        }
        return ans;
    }
};
