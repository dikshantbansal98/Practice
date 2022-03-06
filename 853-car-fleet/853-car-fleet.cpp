class Solution {
public:
    int carFleet(int t, vector<int>& position, vector<int>& speed) {
        double target = t;
        vector<pair<int,int>>representation(position.size());
        vector<double>fleets;
        for(int i = 0; i < position.size(); ++i) {
            representation[i] = {position[i], speed[i]};
        }
        sort(representation.rbegin(), representation.rend());
        fleets.push_back((target-representation[0].first)/representation[0].second);
        for(int i = 1; i < representation.size(); ++i) {
            double time = (target-representation[i].first)/representation[i].second;
            if(time > fleets.back()) {
                fleets.push_back(time);
            }
        }
        return fleets.size();
    }
};