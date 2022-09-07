class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int res = 1;
        auto comp = [&] (vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0] ||
                (a[0] == b[0] && a[1] > b[1] );
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> h;
        vector<int> lis;
        for(int i = 0; i < envelopes.size(); i++)
        {
            h.push_back(envelopes[i][1]);
        }
        for(int i = 0; i < h.size(); i++)
        {
            auto it = lower_bound(lis.begin(), lis.end(), h[i]);
            if(it == lis.end())
            {
                lis.push_back(h[i]);
            }
            else
            {
                *it = h[i];
            }
        }
        return lis.size();
    }
};

// TLE
// int maxEnvelopes(vector<vector<int>>& envelopes) {
//         int res = 1;
//         auto comp = [&] (vector<int>& a, vector<int>& b)
//         {
//             return a[0] < b[0] ||
//                 (a[0] == b[0] && a[1] > b[1] );
//         };
//         sort(envelopes.begin(), envelopes.end(), comp);
//         vector<int> h;
//         for(int i = 0; i < envelopes.size(); i++)
//         {
//             h.push_back(envelopes[i][1]);
//         }
//         vector<int> dp(h.size(), 1);
//         for(int i = 1; i < h.size(); i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(h[i] > h[j])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
