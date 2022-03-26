class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int ans = -1e9;
        for(int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            
            while(pq.size() && pq.top().second < x-k) {
                pq.pop();
            }
            if(pq.size()) {
                ans = max(ans,pq.top().first+y+x);
            }
            pq.push({y-x, x});
        }
        return ans;
    }
};