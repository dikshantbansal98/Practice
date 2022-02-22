class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()), high = 1e8;
        int ans = high;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(count(weights, days, mid)) {
                high = mid-1;
                ans = min(ans,mid);
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    bool count(vector<int>& weights, int days, int mid) {
        int sum = weights[0], count = 1;
        for(int i = 1; i < weights.size(); ++i) {
            if(sum + weights[i] > mid) {
                sum = weights[i];
                count++;
            }
            else {
                sum += weights[i];
            }
        }
        return count <= days;
    }
};