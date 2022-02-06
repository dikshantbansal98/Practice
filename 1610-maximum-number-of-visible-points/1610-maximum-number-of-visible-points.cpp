
double pi = 3.14159;
class Solution {
public:
    double getAngle(int x, int y) {
        return atan2(y,x)*180/pi;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int commonPoints = 0;
        vector<double>angles;
        for(auto &point: points) {
            int xDiff = point[0] - location[0], yDiff = point[1] - location[1];
            if(xDiff == 0 && yDiff == 0) {
                commonPoints++;
                continue;
            }
            double degrees = getAngle(xDiff, yDiff);
            if(degrees < 0) {
                degrees += 360;
            }
            angles.push_back(degrees);
        }
        sort(angles.begin(), angles.end());
        int size = angles.size();
        for(int i = 0; i < size; ++i) {
            angles.push_back(angles[i]+360);
        }
        int ans = 0;
        double givenAngle = angle;
        int start = 0;
        for(int i = 0; i < angles.size(); ++i) {
            while(angles[i]-angles[start] > givenAngle) {
                start++;
            }
            if(i>=start && angles[i]-angles[start] <= givenAngle) {
                ans = max(ans,i-start+1);
            }
        }
        return ans + commonPoints;
    }
};