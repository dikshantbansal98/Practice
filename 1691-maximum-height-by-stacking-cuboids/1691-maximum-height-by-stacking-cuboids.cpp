class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(int i = 0; i < n; ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), [](vector<int>&a, vector<int>&b){
            return a[0]*a[1]*a[2] < b[0]*b[1]*b[2];
        });
        vector<int>dp(n,0);
        for(int i = n-1; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                if(isLess(cuboids[i], cuboids[j])) {
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