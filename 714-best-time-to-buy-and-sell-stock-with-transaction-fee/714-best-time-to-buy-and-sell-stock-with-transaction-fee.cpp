class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int maxi = -prices[0]-fee;
        int prev = 0;
        for(int i = 1; i < n; ++i)
        {
            int cur = max({maxi+prices[i],prev,0});
            maxi = max(maxi,prev-prices[i]-fee);
            prev = cur;
        }
        
        return prev;
    }
};