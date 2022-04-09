
class Solution {
public:
    vector< vector<int> >dp;
    int tallestBillboard(vector<int>& rods) {
        dp = vector< vector<int> >(50000,vector<int>(rods.size(),-1));
        return solve(0,0,0,rods)/2;
        
    }
    int solve(int left, int right, int idx, vector<int>&rods)
    {
        if(idx == rods.size()) {
            return left == right? 0:-1e9;
        }
        if(dp[left-right+5000][idx]!=-1) {
            return dp[left-right+5000][idx];
        }
        int option1 = solve(left+rods[idx],right,idx+1,rods)+rods[idx];
        int option2 = solve(left,right+rods[idx],idx+1,rods)+rods[idx];
        int option3 = solve(left,right,idx+1,rods);
        return dp[left-right+5000][idx] = max({option1, option2, option3});
    }
};