class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 4) {
            return 0;
        }
        int ans = 2e9;
        for(int i = 0; i <= 3; ++i) {
            if(n-i+4 >= 0) {
                ans = min(ans, nums[n-4+i] - nums[i]);
            }
        }
        return ans;
    }
};