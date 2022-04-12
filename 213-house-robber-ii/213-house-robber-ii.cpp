class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        return max(calculateMax(nums, 0, nums.size()-2),
                  calculateMax(nums, 1, nums.size()-1));
    }
    
    int calculateMax(vector<int>&nums, int start, int end) {
        int last = nums[start];
        int previous = max(nums[start+1],last);
        int maxValue = previous;
        for(int i = start+2; i <= end; ++i) {
            int current = max(last+nums[i], previous);
            last = previous;
            previous = current;
            maxValue = max(maxValue, current);
        }
        return maxValue;
    }
};