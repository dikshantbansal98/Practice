class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<2)
            return 0;
        vector<int>dp(prices.size()+1);
    	int maxi = -prices[0],ans=0;
    	for(int i = 1;i< prices.size();++i)
    	{
    		dp[i] = max(dp[i-1],maxi+prices[i]);
    		maxi = max({maxi,dp[i-1]-prices[i],-prices[i]});
    	}    
    	return dp[prices.size()-1];
    }
};