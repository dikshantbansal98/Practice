class Solution {
public:
    int longestValidParentheses(string s) {        
        int ans = 0;
        vector<int>dp(s.size()+1);
        for(int i = 1; i < s.size();++i)
        {
            if(s[i]=='(')
                continue;
            if(s[i-1]=='(')
                dp[i] = 2+ (i>2 ? dp[i-2]:0);
            else
            {
                if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] += 2+dp[i-1];
                    if(i-2-dp[i-1]>=0)
                        dp[i] += dp[i-2-dp[i-1]];
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    
};