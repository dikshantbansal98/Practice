class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 1, left = 0, sum = nums[0];
        for(long long right = 1; right < nums.size(); ++right) {
            sum += nums[right];
            while((right-left+1)*nums[right] > sum+k) {
                sum -= nums[left++];
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};