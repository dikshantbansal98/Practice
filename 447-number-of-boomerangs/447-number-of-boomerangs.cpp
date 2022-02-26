class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i) {
            map<int,int>frequencies;
            for(int j = 0; j < points.size(); ++j) {
                if(i == j) {
                    continue;
                }
                frequencies[distance(points[i], points[j])]++;
            }
            for(auto &[dist, freq] : frequencies) {
                ans += freq*(freq-1);
            }
        }
        return ans;
    }
    int distance(vector<int>&point1, vector<int>&point2) {
        return (point1[0]-point2[0])*(point1[0]-point2[0]) + (point1[1]-point2[1])*(point1[1]-point2[1]);
    }
};