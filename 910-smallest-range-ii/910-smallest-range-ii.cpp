class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = nums.back()-nums.front();
        for(int i = 0; i < nums.size()-1; ++i)
        {
            int mino = min(nums[0]+k,nums[i+1]-k);
            int maxo = max(nums.back()-k,nums[i]+k);
            ans = min(ans,maxo-mino);
        }
        return ans;
    }
};