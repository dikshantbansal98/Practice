class Solution {
public:
    double value = -1;
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double>>dp(prob.size(),vector<double>(target+1,value));
        int rest = prob.size()-target;
        return solve(prob, target, 0, dp, rest);
    }
    double solve(vector<double>& prob, int target, int index, vector<vector<double>>&dp, int rest) {
        if(index == prob.size()) {
            return 1;
        }
        if(dp[index][target]!=value) {
            return dp[index][target];
        }
        double first = target>=1? solve(prob, target-1, index+1, dp, rest)*prob[index]:0;
        double second = rest>=1? solve(prob, target, index+1, dp, rest-1)*(1-prob[index]):0;
        return dp[index][target] = first+second;
    }
};


// x1*x2*(1-x3)(1-x4) + x1*(1-x2)*(x3) + x1x2*(1-x3)
//     x1x2 + x1x3 + x2x3 - 3*x1x2x3
    
// x1x2+x2x3+x3x1 - 2*(x1x2x3+..) + 3(x1x2x3x4)
    
