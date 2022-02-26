class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> newPoints;
        for(auto point: points) {
            if(newPoints.size() && (newPoints.back()[0] == point[0] && newPoints.back()[1] == point[1])) {
                continue;
            }
            newPoints.push_back(point);
        }
        points = newPoints;
        double value = 0;
        for(auto &point: points) {
            value += point[0];
        }
        value/=points.size();
        map<double,map<double,double>>frequencies;
        for(int i = 0; i < points.size(); ++i) {
            frequencies[points[i][1]][value-points[i][0]]++;
        }
        for(auto &[y, frequency]: frequencies) {
            for(auto &[dis,freq]: frequency) {
                if(freq!=frequency[-dis]) {
                    return false;
                }
            }
        }
        return true;
    }
};