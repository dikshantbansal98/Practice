class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>>jobs;
        for(int i = 0; i < startTime.size(); ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int,int>profitAtPoint;
        profitAtPoint[0] = 0;
        int maxProfit = 0;
        for(auto &[end, start, profit]: jobs) {
            auto previous = prev(profitAtPoint.upper_bound(start));
            int currentProfit = profit + previous->second;
            if(profitAtPoint.rbegin()->second < currentProfit) {
                profitAtPoint[end] = currentProfit;
                maxProfit = max(maxProfit, currentProfit);
            }
        }
        return maxProfit;
    }
};