class Solution {
public:
    int jump(vector<int>& nums) {
        int maximum = 0, steps = 0, jumps = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i == nums.size()-1) {
                return jumps;
            }
            maximum = max(maximum, nums[i]+i);
            if(steps == 0) {
                steps = maximum - i;
                jumps++;
            }
            steps--;
        }
        return jumps;
    }
};