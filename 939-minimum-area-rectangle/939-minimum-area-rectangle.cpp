class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size() < 4) {
            return 0;
        }
        int minArea = 1e9;
        set<pair<int,int>>pointsSet = getPointsSet(points);
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i+1; j < points.size(); ++j) {
                pair<int,int> firstPoint = {points[i][0], points[i][1]};
                pair<int,int> thirdPoint = {points[j][0], points[j][1]};
                if(firstPoint.first == thirdPoint.first || thirdPoint.second == firstPoint.second) {
                    continue;
                }
                pair<int,int> secondPoint = {points[i][0], points[j][1]};
                pair<int,int> fourthPoint = {points[j][0], points[i][1]};
                if(pointsSet.find(secondPoint)!=pointsSet.end() && pointsSet.find(fourthPoint)!=pointsSet.end()) {
                    int area = abs(firstPoint.first - thirdPoint.first)*abs(firstPoint.second - thirdPoint.second);
                    minArea = min(minArea, area);
                }
            }
        }
        if(minArea == 1e9) {
            minArea = 0;
        }
        return minArea;
    }
    
    set<pair<int,int>> getPointsSet(vector<vector<int>>& points) {
        set<pair<int,int>>pointsSet;
        for(auto point: points) {
            pointsSet.insert({point[0], point[1]});
        }
        return pointsSet;
    }
    
};