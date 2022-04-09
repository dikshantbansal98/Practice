class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        vector<vector<long>>points(p.size());
        for(int i = 0; i < p.size(); ++i) {
            points[i].push_back(-1e8);
            for(int j = 0; j < p[i].size(); ++j) {
                points[i].push_back(p[i][j]);
            }
            points[i].push_back(-1e8);
        }
        for(int i = 1; i < points.size(); ++i) {
            vector<long>left(points[i].size(),-1e9),right(points[i].size(),-1e9);
            for(int j = 1; j < points[i].size()-1; ++j) {
                left[j] = max(points[i-1][j]+j,left[j-1]);
            }
            for(int j = points[i].size()-2; j >= 1; --j) {
                right[j] = max(points[i-1][j]-j,right[j+1]);
            }
            for(int j = 1; j < points[i].size()-1; ++j) {
                points[i][j] += max(left[j]-j, right[j]+j);
            }
        }
        return *max_element(points.back().begin(), points.back().end());
    }
};
