class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>maximum(prices.size()+1),dp(prices.size());
        for(int i = prices.size()-1;i >= 0; --i)
        {
            if(i==prices.size()-1)
                maximum[i] = prices[i];
            else
                maximum[i] = max(prices[i],maximum[i+1]);
        }
        int minimum = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i] = max(prices[i]-minimum,dp[i-1]);
            ans = max({ans,dp[i-1]+maximum[i+1]-prices[i],dp[i]});
            minimum = min(prices[i],minimum);
        }
        return ans;
    }
};