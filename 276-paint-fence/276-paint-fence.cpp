class Solution {
public:
    int numWays(int n, int k) {
        if(k == 1) {
            return n < 3;
        }
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return k;
        }
        if(n == 2) {
            return k*k;
        }
        vector<int>dp(n+1,1);
        dp[1] = k;
        dp[2] = k*k;
        for(int i = 3; i <= n; ++i) {
            dp[i] = (dp[i-1]+dp[i-2])*(k-1);
        }
        return dp[n];
    }
};