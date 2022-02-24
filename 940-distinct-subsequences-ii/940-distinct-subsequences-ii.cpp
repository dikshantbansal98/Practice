const int mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int>last(26,-1), dp(s.size()+1);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i) {
            dp[i+1] = 2*dp[i]%mod;
            if(last[s[i]-'a'] >= 1) {
                dp[i+1] += mod-dp[last[s[i]-'a']-1];
                dp[i+1]%=mod;
            }
            last[s[i]-'a'] = i+1;
        }
        return dp[s.size()]-1;
    }
};