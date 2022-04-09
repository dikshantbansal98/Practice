class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int>dp(nums.size()); multiset<int>set;
        for(int i = 0; i < nums.size(); ++i) {
            if(i>k) {
                set.erase(set.find(dp[i-k-1]));
            }
            dp[i]=nums[i];
            if(set.size()) {
                dp[i] = max(dp[i],nums[i]+*set.rbegin());
            }
            set.insert(dp[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};