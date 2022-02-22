class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>ratios;
        for(int i = 0; i < quality.size(); ++i) {
            ratios.push_back({1.0*wage[i]/quality[i], quality[i]});
        }
        sort(ratios.begin(),ratios.end());
        priority_queue<int>set;
        double ans = 1e9;
        int sumQ = 0;
        for(int i = 0; i < wage.size(); ++i) {
            set.push(ratios[i].second);
            sumQ += ratios[i].second;
            if(set.size()>k) {
                sumQ -= set.top();
                set.pop();
            }
            if(set.size() == k) {
                ans = min(ans,ratios[i].first*sumQ);
            }
            
        }
        return ans;
    }
};

// 2.5 6 7
// 20 5 10