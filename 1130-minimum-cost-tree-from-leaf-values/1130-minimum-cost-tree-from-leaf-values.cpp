class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
       return solve(0,arr.size()-1,arr,dp);
    }
    int solve(int i, int j,vector<int>&arr,vector<vector<int>>&dp) {
        if(i>=j)
            return 0;
        int ans = 1e9;
        if(dp[i][j] != -1)
            return dp[i][j];
        for(int k = i; k < j; ++k) {
            int left = solve(i,k,arr,dp);
            int right = solve(k+1,j,arr,dp);
            int left_max = *max_element(arr.begin()+i,arr.begin()+ k +1);
            int right_max = *max_element(arr.begin()+k+1,arr.begin()+j+1);
            ans = min(ans,left_max*right_max+left+right);
        }
        return dp[i][j]  = ans;
    }
};