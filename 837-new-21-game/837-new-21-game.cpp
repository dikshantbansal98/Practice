class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n==0 || k==0) {
            return 1;
        }
        vector<double>dp(n+1), prefixes(n+2);
        dp[0] = prefixes[1] = 1;
        double ans = 0;
        for(int i = 1; i < k; ++i) {
            int start = max(0,i-maxPts);
            dp[i] = (prefixes[i]-prefixes[start])/maxPts;
            prefixes[i+1] += prefixes[i]+dp[i];
        }
        for(int i = k; i <= n; ++i) {
            int start = max(0,i-maxPts);
            if(k>start) {
                ans += (prefixes[k]-prefixes[start])/maxPts;
            }
        }
        return ans;
    }
};
