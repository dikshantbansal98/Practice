class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0, ans = 0, lastIndex = 0;
        for(int i = 0; i < nums.size(); ++i) {
            count += 1-nums[i];
            while(count > k) {
                count -= (1-nums[lastIndex++]);
            }
            ans = max(ans, i - lastIndex + 1);
        }
        return ans;
    }
};