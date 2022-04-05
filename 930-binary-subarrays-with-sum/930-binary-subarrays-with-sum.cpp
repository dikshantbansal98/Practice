class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>dp;
        dp[0] = 1;
        int sum = 0, ans = 0;
        for(int &num: nums) {
            sum += num;
            ans += dp[sum-goal];
            dp[sum]++;
        }
        return ans;
    }
};
