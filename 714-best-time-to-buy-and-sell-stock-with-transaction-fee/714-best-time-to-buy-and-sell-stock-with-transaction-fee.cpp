class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>dp(n,0);
        int maxi = -prices[0]-fee;
        for(int i = 1; i < n; ++i)
        {
            dp[i] = max({dp[i],maxi+prices[i],dp[i-1]});
            maxi = max(maxi,dp[i-1]-prices[i]-fee);
        }
        
        return dp[n-1];
    }
};