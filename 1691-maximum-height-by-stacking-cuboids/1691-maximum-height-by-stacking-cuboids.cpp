class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(vector<int>&cuboid:cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int>dp(n,0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(isLess(cuboids[j], cuboids[i])) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    int isLess(vector<int>&a, vector<int>&b) {
        for(int i = 0; i < 3; ++i) {
            if(a[i]>b[i]) {
                return false;
            }
        }
        return true;
    }
};