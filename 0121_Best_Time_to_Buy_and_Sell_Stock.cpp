class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxProfit = 0;
        for(auto& i : prices)
        {
            if(i > buy)
            {
                maxProfit = max(maxProfit, (i-buy));
            }
            else
                buy = i;
        }
        return maxProfit;
    }
};
