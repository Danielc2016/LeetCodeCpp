class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        vector<int> buy(size, 0);
        vector<int> sell(size, 0);
        buy[0] = -prices[0], sell[0] = 0;
        for(int i = 1; i < size; i++)
        {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[size-1];
    }
};


/*
Greedy
keep adding positive sells to the result!
int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                res += ( prices[i] - prices[i-1] );
        }
        return res;
*/
/*
DP
vector : buy, sell

*/
