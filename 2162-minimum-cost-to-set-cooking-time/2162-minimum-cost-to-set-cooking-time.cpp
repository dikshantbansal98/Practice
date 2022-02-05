class Solution {
public:
    int minCostSetTime(int starting, int moveCost, int pushCost, int targetSeconds) {
        int minimum = 1e9;
        for(int i = 0; i <= 9; ++i) {
            for(int j = 0; j <= 9; ++j) {
                for(int k = 0; k <= 9; ++k) {
                    for(int l = 0; l <= 9; ++l) {
                        int seconds = (10*i+j)*60 + 10*k+l;
                        if(seconds == targetSeconds){
                            vector<int>values = {i,j,k,l};
                            int startAt = starting;
                            int cost = 0;
                            int p = 0;
                            while(values[p] == 0) {
                                p++;
                            }
                            while(p<4) {
                                if(startAt != values[p]){
                                    cost += moveCost;
                                }
                                cost += pushCost;
                                startAt = values[p];
                                p++;
                            }
                            minimum = min(cost,minimum);
                        }
                    }
                }
            }
        }
        return minimum;
    }
};