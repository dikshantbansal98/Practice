class Solution {
public:
    unordered_set<int>visited;
    vector<int>directions;
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity, int value = 0) {
        if(jug1Capacity+jug2Capacity<targetCapacity) {
            return false;
        }
        directions = {-jug1Capacity,jug1Capacity,-jug2Capacity,jug2Capacity};
        visited.insert(0);
        return dfs(jug1Capacity,jug2Capacity,targetCapacity,0);
    }
    bool dfs(int jug1Capacity, int jug2Capacity, int targetCapacity, int value) {
        if(value == targetCapacity) {
            return true;
        }
        bool is = false;
        for(int i = 0; i < 4; ++i) {
            int newValue = directions[i]+value;
            if(newValue <= 0 || newValue > jug1Capacity+jug2Capacity || visited.find(newValue)!=visited.end()) {
                continue;
            }
            visited.insert(newValue);
            is = (is || dfs(jug1Capacity,jug2Capacity,targetCapacity,newValue));
        }
        return is;
    }
};
