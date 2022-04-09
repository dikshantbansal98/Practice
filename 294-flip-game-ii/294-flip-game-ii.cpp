class Solution {
public:
    map<string,bool>dp;
    bool canWin(string currentState, bool turn = false) {
        if(currentState.size() < 2) {
            return false;
        }
        // if(dp.find(currentState) != dp.end()) {
        //     return dp[currentState];
        // }
        for(int i = 0; i < currentState.size()-1; ++i) {
            if(currentState[i+1] == '+' && currentState[i] == '+') {
                string newState = currentState;
                newState[i] = newState[i+1] = '-';
                bool can = canWin(newState, !turn);
                if(!can) {
                    return dp[newState] = true;
                }
            }
        }
        return dp[currentState] = false;
    }
};