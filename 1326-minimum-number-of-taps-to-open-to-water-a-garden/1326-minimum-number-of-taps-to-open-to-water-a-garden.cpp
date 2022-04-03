class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,1e9);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i)
        {
            int left = max(i - ranges[i],0), right = min(i + ranges[i], n);
            for(int j = left+1; j <= right; ++j)
                dp[j] = min(dp[j],dp[left]+1);
        }
        if(dp[n]==1e9)
            dp[n] = -1;
        return dp[n];
    }
};