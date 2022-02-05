class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<int>pqL;
        priority_queue<int,vector<int>,greater<int>>pqR;
        long long leftSum, rightSum;
        leftSum = rightSum = 0;
        vector<long long>dp1(3*n),dp2(3*n);
        for(int i = 0; i < n; ++i) {
            pqL.push(nums[i]);
            leftSum += nums[i];
        }
        for(int i = 2*n; i < 3*n; ++i) {
            pqR.push(nums[i]);
            rightSum += nums[i];
        }
        long long ans = leftSum-rightSum;
        dp1[n-1] = leftSum;
        dp2[2*n] = rightSum;
        for(int i = n; i < 2*n; ++i) {
            pqL.push(nums[i]);
            leftSum += nums[i]-pqL.top();
            pqL.pop();
            dp1[i] = leftSum;
        }
        for(int i = 2*n-1; i >= n; --i) {
            pqR.push(nums[i]);
            rightSum += nums[i]-pqR.top();
            pqR.pop();
            dp2[i] = rightSum;
        }
        for(int i = n-1; i < 2*n; ++i) {
            ans = min(ans,(long long)dp1[i]-dp2[i+1]);
        }
        
        return ans;
    }
};