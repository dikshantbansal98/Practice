class Solution {
public:
    vector<vector<int>>dp;
    int strangePrinter(string s) {
        dp = vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
        return solve(0,s.size()-1,s);
    }
    int solve(int i , int j, string &s)
    {
        if(j<i)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 1+solve(i+1,j,s);
        for(int k = i+1;k <=j; ++k)
        {
            if(s[k]==s[i])
            {
                ans = min(ans,solve(i,k-1,s)+solve(k+1,j,s));
            }
        }
        return dp[i][j] = ans;
    }
};