class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            maximum = max(maximum, nums[i]+i);
            if(maximum >= nums.size()-1) {
                return true;
            }
            if(maximum <= i) {
                return false;
            }
        }
        return true;
    }
};