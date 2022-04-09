class Solution {
public:
    bool isMatch(string s, string p) {
        int size1 = s.size(), size2 = p.size();
        vector<vector<bool>>dp(2,vector<bool>(size2+1));
        int k = 0;
        for(int i = 0; i <= size1; ++i)
        {
            for(int j = 0; j <= size2; ++j)
            {
                dp[k][j] = false;
                if(!i&&!j)
                    dp[k][j] = true;
                
                if(i>0 && j>0 && (s[i-1]==p[j-1] || p[j-1] == '?'))
                    dp[k][j] =  dp[1-k][j-1];
                else if(j>0 && p[j-1] == '*')
                {
                    dp[k][j] = dp[k][j-1];
                    if(i>0)
                        dp[k][j] = (dp[k][j] | dp[1-k][j]|dp[1-k][j-1]);
                }
            }
            k = 1-k;
        }
        return dp[1-k][size2];
    }
};