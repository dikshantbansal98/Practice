class Solution {
public:
    vector<vector<int>>dp;
    bool checkValidString(string s) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size()+1,-1));
        return isValid(s, 0, 0);
    }
    bool isValid(string &s, int idx, int count) {
        if(count < 0) {
            return false;
        }
        if(idx == s.size())
            return count == 0;
        if(dp[idx][count]!=-1) {
            return dp[idx][count];
        }
        if(s[idx] == '(')
            return dp[idx][count] = isValid(s, idx + 1, count+1);
        if(s[idx] == ')')
            return dp[idx][count] = isValid(s, idx + 1, count-1);
        return dp[idx][count] = isValid(s, idx+1, count-1) || isValid(s, idx+1, count) || isValid(s, idx+1, count+1);
    }
};