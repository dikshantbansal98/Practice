const int mod = 1e9+7;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        vector<int>last(2,-1);
        bool isZero = false;
        vector<int>dp(binary.size());
        for(int i = 0; i < n; ++i) {
            if(binary[i] == '1') {
                last[1] = i;
                dp[i] = 1;
                break;
            }
            else {
                isZero = true;
            }
        }
        if(last[1] == -1) {
            return isZero;
        }
        for(int i = last[1]+1; i < n; ++i) {
            dp[i] = 2*dp[i-1]%mod;
            if(binary[i] == '0') {
                isZero = true;
            }
            if(last[binary[i]-'0'] >= 1) {
                dp[i] -= dp[last[binary[i]-'0']-1];
            }
            dp[i] = (dp[i] + mod)%mod;
            last[binary[i]-'0'] = i;
        }
	    return dp[n-1] + isZero;
    }
};
