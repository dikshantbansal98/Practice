class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int count = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<bool>>dp(sum/2+1,vector<bool>(count+1,false));
        for(int i = 0; i <= count; ++i)
            dp[0][i] = true;
        for(int i = 1; i <= sum/2; ++i)
            for(int j = 1; j <= count; ++j)
            {
                dp[i][j] = dp[i][j-1];
                if(i>=stones[j-1])
                dp[i][j] = dp[i][j] | dp[i-stones[j-1]][j-1];
            }
        for(int i = sum/2; i >= 0; --i)
            if(dp[i][count])
            {
                return (sum-2*i);
            }
        return -1;
    }
};