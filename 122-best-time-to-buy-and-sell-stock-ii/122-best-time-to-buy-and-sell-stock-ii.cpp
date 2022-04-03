class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<2)
            return 0;
        prices.push_back(0);
        vector<int>dp(prices.size()+1);
        int minimum = 1e9, ans = 0;
        for(int i = 0; i < prices.size()-1; ++i) {
            if(prices[i]>minimum && prices[i]>prices[i+1]) {
                ans += prices[i]-minimum;
                minimum = 1e9;
            }
            else {
                minimum = min(minimum, prices[i]);
            }
        }
        return ans;
    }
};