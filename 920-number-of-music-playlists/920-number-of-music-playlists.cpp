const int mod = 1e9 + 7;
class Solution {
public:
    vector<vector<int>>dp;
    int numMusicPlaylists(int n, int goal, int k) {
        dp = vector<vector<int>>(goal,vector<int>(n+1,-1));
        return solve(0,0,n,goal,k);
    }
    long long solve(int idx, int uniq, int n, int goal, int k) {
        if(idx == goal)
            return uniq == n;
        if(dp[idx][uniq]!=-1)
            return dp[idx][uniq];
        long long value = 0;
        if(n > uniq)
            value = solve(idx+1,uniq+1,n,goal,k)*(n-uniq)%mod;
        if(uniq > k)
            value += solve(idx+1,uniq,n,goal,k)*(uniq-k)%mod;
        return dp[idx][uniq] = value%mod;
    }
};